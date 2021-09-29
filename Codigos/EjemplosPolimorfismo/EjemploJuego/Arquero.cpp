#include "Arquero.h"

Arquero::Arquero() : Personaje("Arquero") {
	
}

// el arquero tiene un ataque especial que usa 3 unidades de man�
// y le quita el triple de energ�a al enemigo que el ataque com�n
void Arquero::Atacar (Personaje & otro) {
	if (m_mana>=3 && otro.VerVida()>1) {
		otro.RecibirAtaque(3);
		m_mana-=3;
	} else {
		Personaje::Atacar(otro);
	}
}

