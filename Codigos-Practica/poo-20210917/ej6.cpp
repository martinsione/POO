#include <iostream>
using namespace std;

class Fraccion {
public:
	Fraccion(int n, int d) : num(n), den(d) { }
	int Num() const { return num; }
	int Den() const { return den; }
	float Real() const { return float(num)/float(den); }
private:
	int num,den;
};

class NroMixto : public Fraccion {
public:
	NroMixto(int pe, int n, int d) : Fraccion(n,d), pent(pe) { }
	int PEnt() const { return pent; }
	float Real() const { return pent + Fraccion::Real(); }
private:
	int pent;
};

class NroMixto {
public:
	NroMixto(int pe, int n, int d) : pent(pe), frac(n,d) { }
	int PEnt() const { return pent; }
	float Real() const { return pent + frac.Real(); }
	int Num() const { return frac.Num(); }
	int Den() const { return frac.Den(); }
private:
	int pent;
	Fraccion frac;
};

// Si bien en c�digo puede parecer m�s "simple" la versi�n por herencia,
// conceptualmente tiene sentido la versi�n por composici�n, ya que un n�mero
// mixto no "es" una fracci�n, sino que est� "formado por" una fracci�n y algo
// m�s (la parte entera)






