#include <iostream>
#include <vector>
using namespace std;

/* a) Defina una clase Carrera que reciba en su constructor el nombre de un
 * evento deportivo y la fecha del mismo. La clase debe tener métodos para
 * consultar estos datos y para gestionar una lista de participantes (nombre de
 * cada uno). */

/* b) Implemente, reutilizando la clase Carrera las clases Formula1 y MotoGP
 * para representar carreras de estas dos categorías. Estas clases deben tener
 * un método CalcularPuntos que reciba el nombre de un participante, la posición
 * en la que finalizó la carrera, y un booleano para indicar si fue el autor de
 * la vuelta más rápida. El método debe validar si el nombre es correcto (está
 * entre los inscriptos) y si lo es retornar la cantidad de puntos que obtuvo
 * (si no es correcto, debe retornar -1). */

/*   -  En la Fórmula 1, los 10 primeros reciben 25, 18, 15, 12, 10, 8, 6, 4, 2
 * y 1 puntos respectivamente. Pero además, si uno de los 10 primeros logra la
 * vuelta rápida, suma un punto adicional. */
/*   -  En Moto GP, los 15 primeros suman puntos según la siguiente escala: 25,
 * 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 (aquí no hay bonificación
 * alguna para quien logre la vuelta rápida). */

/* c) Escriba una función “testCalcularPuntos" para probar el método
 * CalcularPuntos. La función debe poder recibir cualquier tipo de Carrera, y un
 * vector con los nombres de los pilotos en el orden en que arribaron a meta.
 *   Debe mostrar el puntaje resultante de cada uno (o un mensaje alusivo si un
 * nombre no es correcto */

class Carrera {
public:
  // date format yyyy/mm/dd
  Carrera(string name, int date) : m_name(name), m_date(date){};
  string VerNombre() { return m_name; }
  int VerFecha() { return m_date; }
  vector<string> VerParticipantes() { return m_participantes; }
  void AgregarParticipante(string name) { m_participantes.push_back(name); }

  virtual int CalcularPuntos(string name, int pos, bool fastestLap);
  virtual char VerTipo() const = 0;
  virtual ~Carrera() {}

private:
  vector<string> m_participantes;
  string m_name;
  int m_date;
};

class Formula1 : public Carrera {
public:
  Formula1(string name, int date) : Carrera(name, date) {}
  int CalcularPuntos(string name, int pos, bool fastestLap) override {
    vector<string> v = Carrera::VerParticipantes();
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == name)
        break;
      if (i == v.size())
        return -1;
    }
    return fastestLap == true ? (m_puntos[pos - 1] + 1) : m_puntos[pos - 1];
  }
  char VerTipo() const override { return 'F'; }

private:
  // Creo un array de 20 asi al devolver posiciones menores a 10 devuelve un
  // cero;
  int m_puntos[20] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
};

class MotoGP : public Carrera {
public:
  MotoGP(string name, int date) : Carrera(name, date) {}
  int CalcularPuntos(string name, int pos, bool fastestLap) override {
    vector<string> v = Carrera::VerParticipantes();
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == name)
        break;
      if (i == v.size())
        return -1;
    }
    return m_puntos[pos - 1];
  }
  char VerTipo() const override { return 'M'; }

private:
  int m_puntos[22] = {25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
};

/* c) Escriba una función “testCalcularPuntos" para probar el método
 * CalcularPuntos. La función debe poder recibir cualquier tipo de Carrera, y un
 * vector con los nombres de los pilotos en el orden en que arribaron a meta.
 *   Debe mostrar el puntaje resultante de cada uno (o un mensaje alusivo si un
 * nombre no es correcto */
void testCalcularPuntos(Carrera *c, vector<string> participantes) {
  for (int i = 0; i < participantes.size(); i++) {
    cout << "Participante numero: " << (i + 1)
         << " llego a la meta en la posicion" << (i + 1)
         << " y gano: " << c->CalcularPuntos(participantes[i], i, false);
    // No tengo forma de saber quien hizo la vuelta rapida;
  }
};


int main() { return 0; }
