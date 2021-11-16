#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Alumno {
    string nombre;
    int n1, n2;
};

int main() {
    vector<Alumno> v;

    // Cargar el archivo
    ifstream note("archives/5_2-lista.txt"); Alumno aux;
    while ( getline(note, aux.nombre) && note >> aux.n1 >> aux.n2 ) {
        v.push_back(aux);
        note.ignore();
    }
    note.close();

    for (size_t i=0; i<v.size(); i++) {
        cout << "Nombre: " << v[i].nombre << "| Notas: " << v[i].n1 << ", " << v[i].n2 << "\n";
    }

    ofstream fout("archives/5_2-lista.txt.bak"); 
    for(size_t i=0; i<v.size(); i++) {
        fout << v[i].nombre << "\n" << v[i].n1 << " " << v[i].n2 << "\n";
    }


    return 0;
}

