#ifndef JUEGO_H
#define JUEGO_H
#include <vector>
#include "Personaje.h"

/**
* Struct auxiliar que retorna el m�todo Turno de la clase juego para
* pasarle al main detalles sobre qu� ocurri� durante ese turno
**/
struct InfoAtaque {
	int atacante;
	int atacado;
};

/** 
* Clase que modela las reglas generales del juego.
* Modela solo las reglas generales por s� misma, y delega a los m�todos de la
* clase Personaje los detalles que dependen de los personajes
**/
class Juego {
public:
	
	/// El ctor crea a los personajes para el juego
	Juego(int cant_personajes);
	
	/// M�todo que simula un turno/ronda del juego, en el cual se produce un ataque.
	/// El struct que retorna contiene informaci�n sobre qu� ocurri� exactamente en ese ataque.
	InfoAtaque Turno();
	
	///  Para que el main sepa si el juego termin� (porque qued� uno solo vivo), 
	/// o si debe seguir ejecutando m�s turnos
	bool Terminado() const;
	
	// m�todos para que el main o los Personajes puedan consultar el estado del juego, 
	// pero sin poder modificarlo
	int CantPersonajes() const;
	const Personaje &VerPersonaje(int cual) const;
	int VerGanador() const;
	
	/// funci�n auxiliar para elegir un personaje al azar
	int SeleccionarUnoVivo(int que_no_sea_justo_este=-1) const;
	
	/// Dado que los personajes utilizan polimorfismo, se crean con new, y por
	/// eso se necesita un destructor para hacer los correspondientes deletes
	~Juego();
	
private:
	// estado del juego... todo lo que se necesita es el estado de los personajes
	std::vector<Personaje*> m_v;
	
};

#endif

