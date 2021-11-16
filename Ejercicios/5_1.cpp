#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

// ofstream file("/filepath", ios::app) -> Append
// ofstream file("/filepath", ios::trunc) -> Replace
// 

int main() {
    // ifstream file("notes.txt");

    ifstream file;
    file.open("archives/5_1-notes.txt");

    /* if (!file.is_open()) { */
    /*     cerr << "El archivo no se abrio correctamente" << endl; */
    /*     return 1; */
    /* } */

    file.close();

    ofstream archi("archives/5_1-notes.txt", ios::app);
    if (!archi.is_open()) {
        cout << "no lo pude abrir";
        return 1;
    }
    for (size_t i=0; i<10; i++)
        archi << rand()%100 << " ";
    return 0;
}

