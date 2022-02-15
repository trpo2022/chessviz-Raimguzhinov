#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <ostream>
#define board_size 8

using namespace std;

void loading(void) {
    
    cout << "Запускаю партию    " << '-' << flush;
    for(int r = 0; r < 7; r++) {
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

void board(void) {
    char arr[board_size][board_size] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    for(int i = 0; i < board_size; i++) {
        cout << board_size - i; 
        for(int j = 0; j < board_size; j++)
            cout << " " << arr[i][j];
        cout << endl;
    }
    cout << "  a b c d e f g h\n";
}

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "rus");
   
   	char ch = ' ';
    int moves, N;
	string match[N];
  
    string path = "scholars_mate.txt"; //путь к сценарию
    ifstream notation;  
    notation.open(path);

    if(!notation.is_open())
        cout << "Ошибка считывания сценария партии!" << endl;
    
    else {

        string mv;
        for(notation >> mv; !notation.eof() ; notation >> mv) {
            cout << mv << endl;
            moves++;
        }

        loading();
    }
    notation.close(); //закрываем чтение

    system ("clear"); //очищаем консоль чтоб было больше места
    board(); 
    return 0;
}
