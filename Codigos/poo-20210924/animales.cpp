//Programar una clase Animal que tenga un método desplazarse()
#include <vector>
#include <iostream>
using namespace std;
//y otro método tipo(). Los atributos de las clases son el tipo 
//y la especie del animal, cuyos valores deben ser pasados al
//constructor de la clase base.
	
class Animal {
public:
	Animal(string tipo, string especie) : m_tipo(tipo), m_especie(especie) { }
	virtual string desplazare() = 0;
	string tipo() const { return m_tipo; }
	string especie() const { return m_especie; }
	virtual ~Animal() { }
private:
	string m_tipo, m_especie;
};
	
//Programe las clases Mamifero, Ave y Pez, que son hijas de la clase Animal.
//Además deberá sobreescribir el método desplazarse(), de tal manera 
//que devuelve una cadena de texto indicando el tipo de desplazamiento 
//según el tipo: “camina” para el tipo “mamífero”, “vuela” para el tipo 
//“ave” y “nada” para el tipo “pez”.
class Ave : public Animal {
public:
	Ave(string especie) : Animal("ave",especie) { }
	string desplazare() override { return "vuela"; }
};
class Mamifero: public Animal {
public:
	Mamifero(string especie) : Animal("mamifero",especie) { }
	string desplazare() override { return "camina"; }
};
class Pez: public Animal {
public:
	Pez(string especie) : Animal("ave",especie) { }
	string desplazare() override { return "nada"; }
};

//Escriba un programa cliente que permita modelar un Parque y almacene 
//la información de los animales en un único arreglo de 30 elementos y
//luego emita un listado de los mismos describiendo el tipo y la forma 
//de desplazamiento de cada animal. 
	
int main() {
	vector<Animal*> v;

	for (int i=0; i<3; ++i) { 
		cout << "1-ave, 2-mam, 3-pez ? ";
		int cual; cin >> cual;
		cout << "especie ? ";
		string especie; cin >> especie;
		switch(cual) {
		case 1: v.push_back( new Ave(especie) ); break;
		case 2: v.push_back( new Mamifero(especie) ); break;
		case 3: v.push_back( new Pez(especie) ); break;
		default:
			cout << "error" << endl;
		}
	}
	
	for(Animal *a : v) {
		cout << "En el parque hay un " << a->especie() << " que " << a->desplazare() << endl;
	}
	
	for(Animal *a : v) {
		delete a;
	}
	
}
	
//Finalmente responda: ¿Hay entre las clases algún método virtual puro?¿Por qué?
	
