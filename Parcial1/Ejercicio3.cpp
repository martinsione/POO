#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Alumno {
public:
  Alumno(string nombre, int nota1, int nota2, int nota3)
      : m_nombre(nombre), m_nota1(nota1), m_nota2(nota2), m_nota3(nota3) {}
  tuple<float, char> CalcularCondicion() {
    m_promedio = (m_nota1 + m_nota2 + m_nota3) / 3;
    if (m_promedio >= 60) {
      m_condicion = 'P';
    } else if (m_promedio < 40) {
      m_condicion = 'L';
    } else {
      m_condicion = 'R';
    }
    return make_tuple(m_promedio, m_condicion);
  };
  tuple<string, int> VerDatosAlumno() { return make_tuple(m_nombre, m_dni); }
  int VerDni() { return m_dni; }
  char VerCondicion() {
    CalcularCondicion();
    return m_condicion;
  }

private:
  string m_nombre;
  int m_dni;
  float m_nota1, m_nota2, m_nota3, m_promedio;
  char m_condicion;
};

class Materia {
public:
  Materia(vector<Alumno> alumnos, string nombreProfesor, string nombreMateria)
      : m_alumnos(alumnos), m_nombreProfesor(nombreProfesor),
        m_nombreMateria(nombreMateria) {}
  vector<int> Condiciones() {
    // Pos 0 = libres, 1 = regulares, 2 = promocionados
    vector<int> aux_condiciones = {0, 0, 0};
    for (int i = 0; i < m_alumnos.size(); i++) {
      float promedio;
      char condicion;
      tie(promedio, condicion) = m_alumnos[i].CalcularCondicion();
      if (condicion == 'L')
        aux_condiciones[0] += 1;
      if (condicion == 'R')
        aux_condiciones[1] += 1;
      if (condicion == 'P')
        aux_condiciones[2] += 1;
    }
    return aux_condiciones;
  }
  tuple<float, char> BuscarCondicionYPromedio(int dni) {
    int index = -1;
    for (int i = 0; i < m_alumnos.size(); i++) {
      if (dni == m_alumnos[i].VerDni()) {
        index = i;
        break;
      }
    }
    return m_alumnos[index].CalcularCondicion();
  }

private:
  string m_nombreMateria, m_nombreProfesor;
  vector<Alumno> m_alumnos;
};

int main() {
  vector<Alumno> alumnos;
  Materia poo(alumnos, "Juan", "POO");
  for (int i = 0; i < alumnos.size(); i++) {
    cout << "El alumno con dni: " << alumnos[i].VerDni()
         << " esta en la condicion de: " << alumnos[i].VerCondicion() << endl;
  }

  return 0;
}
