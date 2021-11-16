#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>

/**
* Clase para guardar el estado de un personaje e implementar sus acciones espec�ficas.
* Hacemos virtuales los m�todos que queremos que puedan variar seg�n el tipo de personaje,
* ya que por cada tipo espec�fico habr� una herencia.
**/
class Personaje {
	
public:
	
	Personaje(std::string tipo);
	
	// m�todos para consultar el estado del personaje... para mostrar desde el main 
	// o para que otros personajes puedan eventualmente elegir mejor a quien atacar
	std::string VerTipo() const;
	int VerMana() const;
	int VerVida() const;
	bool EstaVivo() const;
	
	/// mediante este m�todo la clase Juego le indica al Personaje que le toca realizar su ataque,
	/// dirigido al otro que recibe como argumento
	virtual void Atacar(Personaje &otro);
	
	/// a medida que el tiempo avanza (en cada turno), se regenera el mana... 
	void RegenerarMana();
	
	/// mediante este m�todo, un personaje recibe un ataque durante un turno, y se defiende o pierde vida
	virtual void RecibirAtaque(int cuanto);
	
	/// si hay m�todos virtuales, por las dudas el destructor debe ser virtual tambi�n
	virtual ~Personaje() { }
	
protected:
	
	// datos y estado del personaje
	std::string m_tipo;
	int m_vida, m_mana;
	
};

#endif

