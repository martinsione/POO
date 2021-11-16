#include <iostream>
#include <vector>
using namespace std;

class Instrumento {
public:
	virtual string VerTipo() const =0;
};

class Tecla {
public:
	Tecla(string n) : m_nota(n) { }
	string VerNota() const { return m_nota; }
	bool EstaApretada() const { return m_apretada; }
	void Apretar() { m_apretada = true; }
	void Soltar() { m_apretada = false; }
private:
	string m_nota;
	bool m_apretada = false;
};

class Pedal {
public:
	Pedal() { }
	float VerPresion() const { return m_presion; }
	void CambiarPresion(float p) { m_presion = p; }
private:
	float m_presion = 0;
};

class Piano : public Instrumento {
public:
	Piano() {
		const string notas[] = { "Do", "Re", "Mi", "Fa", "Sol", "La", "Si" };
		for (int i=0; i<7; ++i) m_teclas.push_back( Tecla(notas[i]) );
	}
	string Apretar(int i) { 
		m_teclas[i-1].Apretar(); 
		return m_teclas[i-1].VerNota();
	}
	void Soltar(int i) { m_teclas[i-1].Soltar(); }
	void CambiarPresion(float p) { m_pedal.CambiarPresion(p); }
	string VerTipo() const override { return "piano"; }
private:
	Pedal m_pedal;
	vector<Tecla> m_teclas;
};

int main() {
	Piano p;
	Instrumento &i = p;
	
	cout << i.VerTipo() << endl;
	cout << p.Apretar(3);
	return 0;
}

