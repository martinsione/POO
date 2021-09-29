#include <iostream>
using namespace std;

class Cuadratica {
    private:
        float m_a, m_b, m_c;

    public:
        void cargarCoeficientes(float a, float b, float c);
        bool tieneRaicesReales();
        float raiz1();
        float raiz2();
        float parteReal();
        float parteImaginaria();
};

int main() {
    cout << "hola";
    return 0;
}
