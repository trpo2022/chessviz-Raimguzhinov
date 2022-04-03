#include <iostream>
#include <libchessviz/print_board.h>
#include <unistd.h>

using namespace std;

void translation(string line, motion& motion)
{
    motion.y1 = board_size - ((int)line[1] - (int)'0');
    motion.x1 = (int)line[0] - (int)'a';
    motion.y2 = board_size - ((int)line[4] - (int)'0');
    motion.x2 = (int)line[3] - (int)'a';
}

void printBoard(char boardrr[board_size][board_size])
{
    cout << endl;
    for (int i = 0; i < board_size; i++) {
        cout << board_size - i << " | ";
        for (int j = 0; j < board_size; j++)
            cout << boardrr[i][j] << " ";
        cout << endl;
    }
    cout << "  +-----------------" << endl;
    cout << "    a b c d e f g h" << endl;
}

void loadingAnimation(int move_cnt)
{
    if (move_cnt % 2 != 0)
        cout << "Ваш ход    ";
    if (move_cnt % 2 == 0)
        cout << "Ход соперника     ";
    cout << '-' << flush;
    for (int r = 0; r < 7; r++) {
        usleep(100000);
        cout << "\b\\" << flush;
        usleep(100000);
        cout << "\b|" << flush;
        usleep(100000);
        cout << "\b/" << flush;
        usleep(100000);
        cout << "\b-" << flush;
    }
}

void takeStep(
        char* step1,
        char* step2,
        int& board_line_pos,
        int& board_column_pos,
        int& board_line_pos2,
        int& board_column_pos2,
        int move_cnt_load,
        char boardrr[board_size][board_size])
{
    string left = "87654321";
    string bottom = "abcdefgh";
    char line = step1[1];
    char column = step1[0];
    board_line_pos = left.find(line);
    board_column_pos = bottom.find(column);
    char line2 = step2[1];
    char column2 = step2[0];
    board_line_pos2 = left.find(line2);
    board_column_pos2 = bottom.find(column2);
    cout << endl;
    move_cnt_load++;
    loadingAnimation(move_cnt_load);
    cout << endl;
    printBoard(boardrr);
}

void turnFigure(
        int x1, int y1, int x2, int y2, char boardrr[board_size][board_size])
{
    char buf_step = boardrr[x1][y1];
    boardrr[x1][y1] = ' ';
    boardrr[x2][y2] = buf_step;
}

bool checkStep(string step, motion motion, char boardrr[board_size][board_size])
{
    switch (step.size()) {
    case 5:
        if ((motion.x1 > 7) || (motion.x1 < 0) || (motion.x2 > 7)
            || (motion.x2 < 0) || (motion.y1 > 7) || (motion.y1 < 0)
            || (motion.y2 > 7) || (motion.y2 < 0)) {
            cout << "\nВыход за пределы доски" << endl;
            return false;
        }
        if (step[2] == '-') {
            if (motion.x1 != motion.x2) {
                cout << "\nПешки двигаются только прямо" << endl;
                return false;
            }
            if (boardrr[motion.y1][motion.x1] == 'P') {
                if (motion.y1 == 6) {
                    if ((motion.y1 - motion.y2 > 2)
                        || (motion.y1 - motion.y2 < 1)) {
                        cout << "\nНачиная с первого хода, пешки могут "
                                "перемещаться на 1-2 клетки"
                             << endl;
                        return false;
                    }
                } else {
                    if (motion.y1 - motion.y2 != 1) {
                        cout << "\nПосле первого хода пешки могут двигаться "
                                "только на 1 клетку вперед"
                             << endl;
                        return false;
                    }
                }
            } else if (boardrr[motion.y1][motion.x1] == 'p') {
                if (motion.y1 == 1) {
                    if ((motion.y2 - motion.y1 > 2)
                        || (motion.y2 - motion.y1 < 1)) {
                        cout << "\nНачиная с первого хода, пешки могут "
                                "перемещаться на 1-2 клетки"
                             << endl;
                        return false;
                    }
                } else {
                    if (motion.y2 - motion.y1 != 1) {
                        cout << "\nПосле первого хода пешки могут двигаться "
                                "только на 1 клетку вперед"
                             << endl;
                        return false;
                    }
                }
            }
        }
        break;
    default:
        return true;
        break;
    }
    return true;
}
