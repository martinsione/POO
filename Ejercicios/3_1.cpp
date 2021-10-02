#include <iostream>
using namespace std;

class Persona {
public:
  Persona(string nombre, string estadoCivil, int dni, int fechaNac)
      : m_nombre(nombre), m_estadoCivil(estadoCivil), m_dni(dni),
        m_fechaNac(fechaNac) {}
  int Edad(int fechaActual) const { return (fechaActual - m_fechaNac) / 10000; }
  string Nombre() const { return m_nombre; }
  string EstadoCivil() const { return m_estadoCivil; }
  int dni() const { return m_dni; }

private:
  string m_nombre, m_estadoCivil;
  int m_dni, m_fechaNac;
};

class Alumno : public Persona {
public:
  Alumno(string nombre, string estadoCivil, int dni, int fechaNac,
         float promedio, int materiasAprobadas)
      : Persona(nombre, estadoCivil, dni, fechaNac), m_promedio(promedio),
        m_materiasAprobadas(materiasAprobadas) {}

  float MeritoAcademico() const { return m_promedio * m_materiasAprobadas; }

private:
  float m_promedio;
  int m_materiasAprobadas;
};

class Docente : public Persona {
public:
  Docente(string nombre, string estadoCivil, int dni, int fechaNac,
          int fechaIngreso)
      : Persona(nombre, estadoCivil, dni, fechaNac),
        m_fechaIngreso(fechaIngreso) {}

  int Antiguedad(int fechaActual) const { return fechaActual - m_fechaIngreso; }

private:
  int m_fechaIngreso;
};

class Curso : public Alumno, public Docente {
public:
  Curso(string nombre, string estadoCivil, int dni, int fechaNac,
        float promedio, int materiasAprobadas)
      : Alumno(nombre, estadoCivil, dni, fechaNac, materiasAprobadas) {}
  Alumno(string nombre, string estadoCivil, int dni, int fechaNac,
         float promedio, int materiasAprobadas)

      float MejorPromedio() const {
    float aux;
  }

private:
};

int main() {
  Persona p("Martin", "Soltero", 44763159, 20030203);
  cout << p.Edad(20210910) << endl;

  return 0;
}
