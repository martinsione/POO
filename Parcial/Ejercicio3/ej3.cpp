#include <iostream>
#include <list>
#include <fstream>
using namespace std;

template <typename T>
T mas_repetido(const list<T> &l) {
    T elemento_mas_repetido;
    int contador_mas_repetido=0;
    for (T it : l) {
        int acum;
        for (T jit : l) {
            if (it == jit) { acum++; }
        }
        if (acum > contador_mas_repetido) {
            contador_mas_repetido = acum;
            elemento_mas_repetido = it;
        }
    }
    return elemento_mas_repetido;
}

struct Ficha {
    int dni;
    string apellido, nombre;
};

ostream &operator<<(ostream &out, Ficha f) {
  return out << f.dni << " " << f.nombre << ", " << f.apellido;
};

int main() {

    /* cout << rand() % 900 + 100; */
    // Cargar lista string
    list<string>s;
    while (true) {
        cout << "Ingrese cadenas de texto: (Presione 0 para finalizar la carga)" << endl;
        string aux;
        getline(cin, aux);
        if (aux == to_string(0)) break;
        s.push_back(aux);
    }

    // Cargar lista int
    list<int>enteros(100);
    for (auto it=enteros.begin(); it!=enteros.end(); it++) {
        *it = (rand()%900)+100;
    }

    // Cargar desde el archivo
    ifstream file("Parcial2/Ejercicio3/archivo.txt");
    list<Ficha>ficha_vector;
    Ficha aux; string s_aux;
    while (file >> aux.dni && getline(file, s_aux)) {
        aux.nombre = s.substr(0, s.find(","));
        aux.apellido = s.substr(s.find(",") + 2);
        ficha_vector.push_back(aux);
    }

    cout << mas_repetido(s) << endl;
    cout << mas_repetido(enteros) << endl;
    cout << mas_repetido(ficha_vector) << endl;


    return 0;
}

