#include "labs.h"

// ������ ������������ ������
/*void firstLab() {
    xlnt::workbook wb;
    wb.load("excel\\results.xlsx");
    auto ws = wb.active_sheet();

    //��������� ����������� ����������
    firstLabIter(ws, bubbleSort, "BUBBLE SORT");
    firstLabIter(ws, quickSortMain, "QUICK SORT");
    firstLabIter(ws, countSort, "COUNT SORT");

    wb.save("excel\\results.xlsx");
}*/

unsigned int comp_col = 3, swap_col = 6, general_row = 5;

/*void firstLabIter(xlnt::worksheet ws, double(*sort_algorithm)(bool), std::string sort_name) {
    font = TTF_OpenFont("fonts\\Montserrat-Regular.ttf", 25);

    std::string text = "PROCESSING " + sort_name;
    std::cout << text << std::endl;

    drawText(text.c_str(), font, {252, 247, 235, 200},
             SCREEN_WIDTH / 2,
             SCREEN_HEIGHT / 2);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    for (auto case_ = FIRST_LAB_CASES::BEST_CASE; case_ < FIRST_LAB_CASES::TOTAL_CASES;
         case_ = static_cast<FIRST_LAB_CASES>(case_ + 1)) {
        for (int iter = 0, size = 1000; iter < 3; iter++, size *= 10) {
            if (sort_algorithm == countSort) {
                sortIter(size, case_, sort_algorithm, 1000);
            } else {
                sortIter(size, case_, sort_algorithm, size);
            }

            // ������ ������ � �������
            ws.cell(xlnt::cell_reference(comp_col, general_row)).value(comparisons);
            ws.cell(xlnt::cell_reference(swap_col, general_row)).value(swaps);

            if (comparisons != 0) {
                ws.cell(comp_col + 1, general_row)
                        .value(double(comparisons) /
                               stoll(static_cast<std::string>(ws.cell(comp_col - 1, general_row).to_string())));
            }

            if (swaps != 0) {
                ws.cell(swap_col + 1, general_row)
                        .value(double(swaps) /
                               stoll(static_cast<std::string>(ws.cell(swap_col - 1, general_row).to_string())));
            }
            general_row++;
        }
        general_row++;
    }
    general_row += 4;
}*/

void sortIter(unsigned int size, FIRST_LAB_CASES case_, double(*sort_algorithm)(bool), int max_rand) {
    // ������� ������
    SDL_RenderClear(renderer);

    updateArraySize(size, max_rand);

    // ���������� � ������������ �������(� ����������� �� ���� �����)
    if (case_ == BEST_CASE) {
        sortInOrder(true);
    } else if (case_ == WORST_CASE) {
        sortInOrder(false);
    }

    // ����������� ������ � �������� ������
    prepareArray();

    std::cout << "\nARRAY BEFORE SORT ----> ";

    cmdColorText(shortPrintArray(), COLORS::LIGHTBLUE);

    //����� ����������� � ����������� ���������
    std::string text = "SORTED " + std::to_string(size) + " ELEMENTS IN " +
                       std::to_string(sort_algorithm(false)) + // <---- ��� ����������� ������������� ��������
                       " SECONDS";

    font = TTF_OpenFont("fonts\\Montserrat-Regular.ttf", 35);
    drawText(text.c_str(), font, {252, 247, 235, 200}, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    std::cout << "ARRAY AFTER SORT  ----> ";
    cmdColorText(shortPrintArray(), COLORS::BLUE);

    // ����� ����������� 
    cmdColorText("\n" + text, COLORS::LIGHTGREEN);
    cmdColorText(" (comparisons=" + std::to_string(comparisons) + " , "
                                                                  "swaps=" + std::to_string(swaps) + ")\n",
                 COLORS::WHITE);

    //���������� ������
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
}

// ������ ������������ ������
void secondLab() {
    SDL_RenderClear(renderer);
    BinaryTree tree = BinaryTree();
    int nodes[] = {24, 27, 14, 0, 7, 17, 28, 19, 4, 3, 25, 10, 6, 16, 8};

    // ������� ������ � ������
    for (auto &index: nodes) {
        tree.insertNode(&tree, tree.root, index);
    }

    SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, IMG_Load("images\\main\\bg.png")), NULL, NULL);
    tree.drawTree(&tree, tree.root, ARRAY_HEIGHT / tree.getHeight(tree.root) * 0.6f, SCREEN_WIDTH / 2,
                  SCREEN_HEIGHT * 0.2, 0, 0);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    SDL_RenderClear(renderer);

    tree = BinaryTree();

    // ���������� ������ ������������� �������
    inplaceHeapSort(nodes, sizeof(nodes) / sizeof(nodes[0]), false);

    // ������� ��� �������������� �����
    for (auto &index: nodes)
        tree.insertNode(&tree, tree.root, index);

    SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, IMG_Load("images\\main\\bg.png")), NULL, NULL);
    tree.drawTree(&tree, tree.root, ARRAY_HEIGHT / tree.getHeight(tree.root) * 0.6f, SCREEN_WIDTH / 2,
                  SCREEN_HEIGHT * 0.25, 0, 0);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    SDL_RenderClear(renderer);

    tree.balanceTree(tree);

    SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, IMG_Load("images\\main\\bg.png")), NULL, NULL);
    tree.drawTree(&tree, tree.root, ARRAY_HEIGHT / tree.getHeight(tree.root) * 0.375f, SCREEN_WIDTH / 2,
                  SCREEN_HEIGHT * 0.3, 0, 0);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
}
