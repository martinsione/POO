#include <iostream>
using namespace std;


class VectorDinamico {
public:
	VectorDinamico(int n, int max) {
		m_p = new int[n]; m_n = n;
		for (int i=0; i<n; ++i)
			m_p[i] = rand()%(max+1);
	}
	VectorDinamico(const VectorDinamico &otro) {
		m_p = new int[otro.m_n]; m_n = otro.m_n;
		for (int i=0; i<otro.m_n; ++i) { 
			m_p[i] = otro.m_p[i];	
		}
	}

	int VerTamanio() const { return m_n; }
	
	void Duplicar() {
		...completar basado en la func redimensionar de la guia 1...
	}
	
	int VerElemento(int i) const { return m_p[i]; }
	void ModifElemento(int i, int x)  { m_p[i] = x; }
//	int &Elemento(int i) { return m_p[i]; }

	~VectorDinamico() {
		delete [] m_p;
	}
private:
	int *m_p, m_n;
};

int main() {
	VectorDinamico v(5, 10);
	for (int i=0; i<v.VerTamanio(); ++i) { 
		cout << v.VerElemento(i) << " ";
	}
	return 0;
}

