#include <iostream>
#include <tuple>
#include <fstream>
#include <vector>
using namespace std;

vector<int> leer_archivo() {
    vector<int>v; int aux;
    ifstream data_in("data20211104.txt");
    while (data_in >> aux) {
        v.push_back(aux);
        data_in.ignore();
    }

    return v;
}

tuple<int, int, vector<int>>procesa_secuencia(vector<int>&v) {
    vector<int>aux_v(v.size()-1);
    int medio_del_array = (v.size()+1);
    if (v.size()%2!=0) {
        for (size_t i=(medio_del_array-1); i<medio_del_array; i++) {
            aux_v[i] = v[i+1];
        }
        v = aux_v;
    }

    sort(v.begin(), (v.size()/2));
    shuffle(((v.size()/2)+1), v.end());

    int suma1 = 0, suma2 = 0;
    for (size_t i=0; i<((v.size()/2)+1); i++) {
        suma1 += v[i];
    }

    for (size_t i=((v.size()/2)+1); i<v.size(); i++) {
        suma2 += v[i];
    }


    return make_tuple(suma1,suma2, v);
}

int main() {
    vector<int>v;
    v = leer_archivo();
    int n1, n2;
    tie(n1, n2, v) = procesa_secuencia(v);
    cout << n1 << n2;

    ofstream data_out("data20211104.txt");
    cout << "Secuencia modificada" << endl;
    for (size_t i=0; i<v.size(); i++) {
        cout << v[i];
        data_out << v[i] << endl;
    }


    return 0;
}

