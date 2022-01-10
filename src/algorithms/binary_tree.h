#pragma once

#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include"../draw/draw.h"
#include"../globals.h"
#include"../utilities/cmd_color_text.h"
#include"../utilities/module_vector.h"
#include "math.h"

class BinaryTree {
public:
    struct Node {
        int data;
        Node *left, *right;
    };
    Node *root;
    int size;

    BinaryTree() {
        this->root = nullptr;
        size = 0;
    }

    Node *createNode(int data);

    Node *insertNode(BinaryTree *tree, Node *root, int data);

    void drawTree(BinaryTree *tree, Node *node, int radius, int x, int y, int multiplier, int level);

    void drawNode(BinaryTree *tree, Node node, int radius, int x1, int y1, int x2, int y2, int level);

    int getHeight(Node *node);

    void balanceTree(BinaryTree &T);

    void inorder(Node *pointer, std::vector<Node *> &nodes, bool print = false);

    Node *buildBalanced(BinaryTree &T, std::vector<Node *> &nodes, int start, int end);
};
