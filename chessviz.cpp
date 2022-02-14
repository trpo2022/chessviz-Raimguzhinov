#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

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
    cout << "здесь будет доска" << endl;
    return 0;
}
