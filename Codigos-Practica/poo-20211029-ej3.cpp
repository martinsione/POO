#include <iostream>
using namespace std;

// clase vector que pide el ejercicio
template<typename T>
class vector {
public:
	template<typename PFunc> // PFunc func representa a la func que nos den para generar los aleatorios
	vector(int n, PFunc func) : m_n(n), m_p(new T[n]) { 
		for (int i=0; i<n; ++i) { 
			m_p[i] = func();
		}
	}
	~vector() {
		delete [] m_p;
	}
	const T &operator[](int i) const {
		return m_p[i];
	}
	T &operator[](int i) {
		return m_p[i];
	}
	int size() const { return m_n; }
private:
	int m_n;
	T *m_p;
	
	// esta prohibido (por eso en private) copiar hasta que se implementen las copias como se debe
	// (el ctor y el oper. de copia por defecto copian los punteros, no los datos apuntados)
	vector(const vector &v);
	vector &operator=(const vector &v);
};

// funcion auxiliar para mostrar los vectores que generamos
template<typename T>
void mostrar(const vector<T> &v) {
	for (int i=0; i<v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}


// tipo de dato definido por el usuario, para probar la clase con algo que no sea un tipo básico
struct Fraccion {
	int num, den;
};
ostream &operator<<(ostream &o, const Fraccion &f) {
	return o << f.num << '/' << f.den;
}

// generador de valores aleatorios para los diferentes tipos
int int_rand() { return rand()%101; }
double dbl_rand() { return double(rand())/RAND_MAX; }
string str_rand() {
	int n = 3+rand()%8;
	string s(n,'a');
	for(char &c : s)
		c += rand()%('z'-'a');
	return s;
}
Fraccion f_rand() {
	Fraccion f;
	f.num = rand()%101;
	f.den = rand()%100+1;
	return f;
}

// main que prueba generar y mostrar con distintos tipos
int main() {
	vector<int> v1(5,int_rand);
	vector<double> v2(5,dbl_rand);
	vector<string> v3(5,str_rand);
	vector<Fraccion> v4(5,f_rand);
	mostrar(v1);
	mostrar(v2);
	mostrar(v3);
	mostrar(v4);
	return 0;
}

