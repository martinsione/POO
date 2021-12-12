/// Un archivo de texto "medallas.txt" contiene una línea por cada país que 
/// participa en los juegos olímpicos. Cada línea incluye, separados por 
/// espacios primero 3 valores enteros y luego el nombre completo del país.
	
/// Escriba una función que reciba los nombre de los países que representan
/// los tres ganadores de medallas de una competencia y actualice el archivo.

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

struct Medallas {
	int oro,plata,bronce;
};

map<string,Medallas> cargar_medallero() {
	map<string,Medallas> m;
	ifstream f("medallas.txt");
	Medallas aux; string pais;
	while (f>>aux.oro>>aux.plata>>aux.bronce and f.ignore() and getline(f,pais))
		m[pais] = aux;
	return m;
}

void guardar_medallero(const map<string,Medallas> &m) {
	ofstream f("medallas.txt",ios::trunc);
	for(auto p : m) 
		f << p.second.oro << ' ' << p.second.plata << ' '
		  << p.second.bronce << ' ' << p.first << endl;
}

void actualizar_medallero(string p_oro, string p_plata, string p_bronce) {
	
	map<string,Medallas> m = cargar_medallero();
	
	m[p_oro].oro++;
	m[p_plata].plata++;
	m[p_bronce].bronce++;
	
	guardar_medallero(m);
	
}

int main() {
	
	
	string p_oro, p_plata, p_bronce;
	cout << "Ingrese el nombre del pais que gano la medalla de oro: ";
	getline(cin,p_oro);
	cout << "Ingrese el nombre del pais que gano la medalla de plata: ";
	getline(cin,p_plata);
	cout << "Ingrese el nombre del pais que gano la medalla de bronce: ";
	getline(cin,p_bronce);
	
	actualizar_medallero(p_oro,p_plata,p_bronce);
	
	return 0;
}

