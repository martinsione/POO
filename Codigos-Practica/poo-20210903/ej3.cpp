#include <iostream>
#include <cmath>
using namespace std;

const double PI = 2*acos(0);

class Cilindro {
public:
	
	Cilindro() { m_radio = m_altura = 0; }
//	Cilindro() : m_radio(0), m_altura(0) { }
	
	Cilindro(float radio, float altura) {
		m_radio = radio;
		m_altura = altura;
	}
//	Cilindro(float radio, float altura) : m_radio(radio), m_altura(altura) {}
	
 	void asignarDatos(float radio, float altura) {
		m_radio = radio; m_altura = altura;
	}
	
	float obtenerVolumen() const {
		return PI*m_radio*m_radio*m_altura;
	}
	
	float obtenerArea() const {
		return 2*PI*m_radio*m_altura + 2*PI*m_radio*m_radio;
	}
	
private:
	float m_radio,m_altura;
};

int main() {
	
	Cilindro c1, c2(5.3,10.2);
	
	float r,h;
	cin >> r >> h;
	c1.asignarDatos(r,h);
	
	cout << "vol de c1: " << c1.obtenerVolumen() << endl;
	cout << "vol de c2: " << c2.obtenerVolumen() << endl;
	
	return 0;
}




