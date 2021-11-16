#include <iostream>
#include <fstream>
using namespace std;

struct Par {
    int i;
    double d;
};

Par escribir_archivo() {
    Par p;
    ofstream archi_out("archives/6_1-datos.bin", ios::binary);
    for (size_t i=0; i<15; i++) {
        p.i = rand()%100;
        p.d = rand()%100/100.0;
        cout << p.i << " " << p.d << endl;
        archi_out.write(reinterpret_cast<char*>(&p), sizeof(p));
    }
    return p;
}

Par leer_archivo() {
    Par p;
    ifstream archi_in("archives/6_1-datos.bin", ios::binary|ios::ate);
    int size_of_archive = archi_in.tellg() / sizeof(Par);
    archi_in.seekg(0); // Me lleva a la posicion 0
    for (size_t i=0; i<size_of_archive; i++) {
        archi_in.read(reinterpret_cast<char*>(&p), sizeof(p));
        cout << i << ": " << p.i << " " << p.d << endl;
    }
    return p;
}

int main() {
    // Con ios::ate -> Abre el archivo al final y con el tellg() tengo el tamaño del archivo

    /* escribir_archivo(); */
    leer_archivo();

    return 0;
}

