/// Escriba una función que reciba el nombre de un archivo binario que
/// contenga un conjunto de registros de un tipo genérico, y elimine del
/// archivo todos los registros repetidos. La función debe retornar la
/// cantidad de elementos eliminados. 

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


template<typename T>
vector<T> cargar(string nom_archivo) {
	ifstream archi(nom_archivo,ios::binary|ios::ate);
	int n = archi.tellg()/sizeof(T);
	vector<T> v(n);
	archi.seekg(0);
	for(T &f : v) 
		archi.read(reinterpret_cast<char*>(&f),sizeof(T));
	return v;
}

template<typename T>
void guardar(const vector<T> &datos, string nom_archivo) {
	ofstream archi(nom_archivo,ios::trunc|ios::binary);
	for(const T &arch : datos) 
		archi.write(reinterpret_cast<const char*>(&arch),sizeof(T));
}

template<typename T>
int eliminarRepetidos(vector<T> &datos) {
	sort(datos.begin(),datos.end());
	auto it = unique(datos.begin(),datos.end());
	int n = datos.end() - it;
	datos.erase(it,datos.end());
	return n;
}

// versión alternativa, sin reordenar la lista para el unique
template<typename T>
int eliminarRepetidos_sin_ordenar(vector<T> &datos) {
	int n = 0;
	for (size_t i=0; i<datos.size(); ++i) { 
		auto it = remove(datos.begin()+i+1, datos.end(), datos[i]);
		n += datos.end()-it;
		datos.erase(it,datos.end());
	}
	return n;
}
	
template<typename T>
int eliminarRepetidos(string nom_archivo) {
	vector<T> datos = cargar<T>(nom_archivo);
	int n = eliminarRepetidos(datos);
	guardar(datos,nom_archivo);
	return n;
}

int main() {
	int n = eliminarRepetidos<float>("flotantes.dat");
	cout << "habia " << n << " repetidos" << endl;
	return 0;
}

	
