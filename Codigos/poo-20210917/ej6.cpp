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

// Si bien en código puede parecer más "simple" la versión por herencia,
// conceptualmente tiene sentido la versión por composición, ya que un número
// mixto no "es" una fracción, sino que está "formado por" una fracción y algo
// más (la parte entera)






