#include <iostream>
#include <cmath>
using namespace std;

class Tanque {
public: 
    Tanque(float peso) : m_peso(peso) {}
    float asignarPeso(float peso) { return m_peso = peso; }
    float VerVolumen() { return CalcularVolumen(); }
    float VerPeso() { return m_peso; }
    virtual float CalcularVolumen() = 0;
    virtual ~Tanque() {};
private:
    float m_peso;
    float m_volumen;
};

class Cilindro : public Tanque {
public:
    Cilindro(float peso, float altura, float radio) : Tanque(peso), m_altura(altura), m_radio(radio) {}
    float CalcularVolumen() override {
        return (M_PI * pow(m_radio, 2));
    } 
private:
    float m_peso, m_altura, m_radio;
};

class Esfera : public Tanque {
public:
    Esfera(float peso, float altura, float radio) : Tanque(peso), m_altura(altura), m_radio(radio) {}
    float CalcularVolumen() override {
        return (4.0/3 * M_PI * pow(m_radio, 3));
    }
private:
    float m_altura, m_radio;
};

int main() {
    Tanque *p;
    p = new Cilindro(40, 3, 4);
    cout << "El volumen del cilindro es de: " << p->VerVolumen() << endl;
    p = new Esfera(40, 3, 4);
    cout << "El volumen de la esfera es de: " << p->VerVolumen() << endl;
    delete p;

    return 0;
}

