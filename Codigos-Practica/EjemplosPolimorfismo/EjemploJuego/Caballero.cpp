#include "Caballero.h"

Caballero::Caballero() : Personaje("Caballero") {
	
}

// el caballero utiliza su man� para potenciar su ataque y quitarle
// al enemigo la mitad de su energ�a
void Caballero::Atacar (Personaje & otro) {
	if (m_mana>=8 and otro.VerVida()>3) {
		otro.RecibirAtaque( otro.VerVida()/2 );
		m_mana -= 8;
	} else {
		Personaje::Atacar(otro);
	}
}

