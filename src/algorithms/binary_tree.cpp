#include "binary_tree.h"

BinaryTree::Node *BinaryTree::createNode(int data) {
    BinaryTree::Node *newNode = new BinaryTree::Node();
    if (!newNode) {
        std::cout << "Can`t allocate more memory\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BinaryTree::Node *BinaryTree::insertNode(BinaryTree *tree, BinaryTree::Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
        tree->root = root;
        size++;
        return root;
    }

    std::queue<BinaryTree::Node *> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTree::Node *temp = q.front();
        q.pop();

        if (data < temp->data) {
            if (temp->left != NULL)
                q.push(temp->left);
            else {
                temp->left = createNode(data);
                size++;
                return root;
            }
        } else {
            if (temp->right != NULL)
                q.push(temp->right);
            else {
                temp->right = createNode(data);
                size++;
                return root;
            }
        }
    }
}

int BinaryTree::getHeight(BinaryTree::Node *node) {
    if (!node) {
        return 0;
    }

    int left = getHeight(node->left);
    int right = getHeight(node->right);
    return fmax(left, right) + 1;
}

void BinaryTree::drawTree(BinaryTree *tree, BinaryTree::Node *node, int radius, int x, int y, int multiplier,
                          int level = 0) {
    if (node != nullptr) {
        int tree_height = getHeight(tree->root);
        float width_multiplier = (2 - level * 0.35) > 0 ? (2 - level * 0.35) : 0.2;
        float width_x = log2(size) + 1 < tree_height ? tree_height : tree_height * 2 - 1;
        int x1 = x + multiplier * (ARRAY_WIDTH / width_x * width_multiplier);
        int y1 = y + abs(multiplier) * (ARRAY_HEIGHT / tree_height);

        double dx = x1 - x;
        double dy = y1 - y;

        double l = sqrt(dx * dx + dy + dy);
        dx /= l;
        dy /= l;

        drawNode(tree, *node, radius / (level * 0.08 + 1), x, y, x1, y1, level);
        drawTree(tree, node->left, radius, x1, y1, -1, level + 1);
        drawTree(tree, node->right, radius, x1, y1, 1, level + 1);
    }
}

void
BinaryTree::drawNode(BinaryTree *tree, BinaryTree::Node node, int radius, int x1, int y1, int x2, int y2, int level) {
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    int circle_width = radius * 0.15 > 1 ? radius * 0.15 : 1;
    drawSelectedCircle(x2, y2, radius, circle_width, 255, 255, 255, 200);

    drawText(std::to_string(node.data).c_str(), TTF_OpenFont("fonts\\Montserrat-SemiBold.ttf", int(1.3 * radius)),
             {255, 255, 255, 200}, x2, y2);
}

void BinaryTree::balanceTree(BinaryTree &T) {
    BinaryTree::Node *pointer = T.root;
    std::vector<BinaryTree::Node *> nodes;
    inorder(pointer, nodes);
    int n = int(nodes.size());
    T.root = buildBalanced(T, nodes, 0, n - 1);
}

void BinaryTree::inorder(BinaryTree::Node *pointer, std::vector<BinaryTree::Node *> &nodes, bool print) {
    if (pointer == nullptr)
        return;

    if (print) {
        cmdColorText(std::to_string(pointer->data), COLORS::AQUA);
        std::cout << " ";
    }

    inorder(pointer->left, nodes, print);
    nodes.push_back(pointer);
    inorder(pointer->right, nodes, print);
}

BinaryTree::Node *BinaryTree::buildBalanced(BinaryTree &T, std::vector<BinaryTree::Node *> &nodes, int start, int end) {
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    BinaryTree::Node *pointer = nodes[mid];

    pointer->left = buildBalanced(T, nodes, start, mid - 1);
    inorder(T.root, nodes, true);
    std::cout << std::endl;
    pointer->right = buildBalanced(T, nodes, mid + 1, end);

    return pointer;
}