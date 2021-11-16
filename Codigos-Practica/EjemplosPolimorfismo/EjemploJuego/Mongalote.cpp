#include "Mongalote.h"

Mongalote::Mongalote() : Personaje("Mongalote") {
	
}

// el mongalote puede utilizar su man� para realizar hacerse
// invulnerable ante un ataque
void Mongalote::RecibirAtaque (int cuanto) {
	if (m_mana>=5) {
		m_mana -=5;
	} else {
		Personaje::RecibirAtaque(cuanto);
	}
}

