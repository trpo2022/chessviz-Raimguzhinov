#include <fstream>
#include <iostream>
#include <libchessviz/open_game.h>

using namespace std;

int readCommand(
        string line,
        motion motion,
        int move_cnt,
        char boardrr[board_size][board_size])
{
    int t = line.find("-");
    int s = line.length();
    int pos_gor1, pos_ver1, pos_gor2, pos_ver2;
    char step_start[t], step_end[s];
    for (int i = 0; i < t; i++) {
        step_start[i] = line[i];
    }
    for (int i = t + 1, j = 0; i < s; i++, j++) {
        step_end[j] = line[i];
    }
    takeStep(
            step_start,
            step_end,
            pos_gor1,
            pos_ver1,
            pos_gor2,
            pos_ver2,
            move_cnt,
            boardrr);
    translation(line, motion);
    if (checkStep(line, motion, boardrr) == true) {
        turnFigure(pos_gor1, pos_ver1, pos_gor2, pos_ver2, boardrr);
        return 0;
    } else
        return 1;
    move_cnt++;
}

void openNotation(
        string path, motion motion, char boardrr[board_size][board_size])
{
    ifstream notation;
    notation.open(path);

    if (!notation.is_open()) {
        cout << endl;
        cout << "Ошибка считывания сценария партии!" << endl;
    } else {
        string mv;
        int cnt = 0;
        for (notation >> mv; !notation.eof(); notation >> mv) {
            readCommand(mv, motion, cnt, boardrr);
        }
        cout << endl;
        loadingAnimation(cnt);
    }
    notation.close(); //закрываем чтение
}
