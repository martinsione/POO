#include <iostream>
using namespace std;

class Vector {
public:
  Vector(int size) : m_size(size) { m_vector = new int[size]; }
  ~Vector() { delete[] m_vector; }
  void Duplicar() {
    int *aux = m_vector;
    m_size *= 2;
    m_vector = new int[m_size];
    *m_vector = *aux;
    /* cout << m_vector << endl; */
  }
  int VerElemento(int index) const { return m_vector[index]; }
  void AsignarElemento(int index, int number) const {
    m_vector[index] = number;
  }
  int size() const { return m_size; }

private:
  int *m_vector;
  int m_size;
};

int main() {
  Vector arr(10);
  cout << arr.size() << endl;
  arr.AsignarElemento(1, 9);
  arr.Duplicar();
  for (size_t i = 0; i < arr.size(); i++) {
    cout << "[" << i << "]= " << arr.VerElemento(i) << endl;
  }
  cout << arr.size() << endl;

  return 0;
}
