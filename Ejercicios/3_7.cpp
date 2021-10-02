#include <iostream>
using namespace std;

class Tecla {
public:
  Tecla() {}
  Tecla(string nota) : m_nota(nota) {}
  string VerNota() { return m_nota; }
  void Apretar() { m_estado = true; }
  void Soltar() { m_estado = false; }
  bool EstaApretada() { return m_estado; }

private:
  string m_nota;
  bool m_estado;
};

class Pedal {
public:
  Pedal() : m_presion(0) {}
  void CambiarPresion(float presion) { m_presion = presion; }
  float VerPresion() { return m_presion; }

private:
  float m_presion;
};

class Instrumento {
public:
  Instrumento() {}
  virtual ~Instrumento() {}
  virtual string VerTipo() { return "sin_nombre"; }

private:
};

class Piano : public Instrumento, Tecla, Pedal {
public:
  Piano() {
    string notas[7] = {"do", "re", "mi", "fa", "sol", "la", "si"};
    for (size_t i = 0; i < 7; i++)
      m_notas[i] = Tecla(notas[i]);
  }
  string VerTipo() { return "Piano"; }
  string Apretar(int numero) {
    m_notas[numero - 1].Apretar();
    return m_notas[numero - 1].VerNota();
  }
  void Soltar(int numero) { m_notas[numero - 1].Soltar(); }
  void Presionar(int presion) { m_pedal.CambiarPresion(presion); }

private:
  Pedal m_pedal;
  Tecla m_notas[7];
};

int main() {
  Piano p;
  p.Soltar(0);
  p.Presionar(2);
  cout << p.VerTipo() << endl;
  cout << p.Apretar(3) << endl;

  return 0;
}
