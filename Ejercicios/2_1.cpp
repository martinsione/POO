#include <cmath>
#include <iostream>
using namespace std;

class Cilindro {
public:
  Cilindro(float radius, float height) {
    m_radius = radius;
    m_height = height;
  };
  void asignarDatos(float radius, float height) {
    m_radius = radius;
    m_height = height;
  }
  float obtenerVolumen() const {
    return M_PI * m_height * (m_radius * m_radius);
  }

private:
  int m_radius;
  int m_height;
};

int main() {
  Cilindro c1(3, 4), c2(5.3, 10.2);
  cout << "Volumen de c1: " << c1.obtenerVolumen() << endl;
  c1.asignarDatos(5.3, 10.2);
  cout << "Volumen de c1: " << c1.obtenerVolumen() << endl;
  cout << "Volumen de c2: " << c2.obtenerVolumen() << endl;

  return 0;
}
