#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");
    string path = "scholars_mate.txt";
    ofstream fout;
    fout.open(path);
    return 0;
}
