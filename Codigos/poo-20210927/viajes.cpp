#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Viaje {
	string origen, destino, medio;
	int distancia;
public:
	Viaje(string orig, string dest, string med, int dst) {
		origen = orig; destino = dest; medio = med; distancia = dst;
	}
	string VerOrigen() const { return origen; }
	string VerDestino() const { return destino; }
	string VerMedio() const { return medio; }
	int VerDistancia() const { return distancia; }
	virtual float CalcTiempo() const = 0;
};

class ViajeEnAuto : public Viaje {
public:
	ViajeEnAuto(string orig, string dest, int dst) : Viaje(orig,dest,"auto",dst) { }
	float CalcTiempo() const override {
		return VerDistancia()/110.0 + .5*(VerDistancia()/220);
	}
};

class ViajeEnAvion : public Viaje {
public:
	ViajeEnAvion(string orig, string dest, int dst) : Viaje(orig,dest,"avion",dst) { }
	float CalcTiempo() const override {
		return VerDistancia()/900.0+2;
	}
};

class ViajeEnColectivo: public Viaje {
public:
	ViajeEnColectivo(string orig, string dest, int dst) : Viaje(orig,dest,"colectivo",dst) { }
	float CalcTiempo() const override {
		return VerDistancia()/90.0;
	}
};

float calcTiempoTotal(const vector<Viaje*> &v) {
	float total = 0;
	for(Viaje *p : v)
		total += p->CalcTiempo();
	return total;
}

int main1() {
	ViajeEnAuto v1("Rosario","Paraná",200);
	ViajeEnAvion v2("Paraná","Buenos Aires",400);
	ViajeEnColectivo v3("Buenos Aires","Rosario",320);
	vector<Viaje*> v = { &v1, &v2, &v3 };
	cout << "Te vas a pasar " << calcTiempoTotal(v) << "hs viajando" << endl;
	return 0;
}

int main2() {
	vector<Viaje*> v;
	v.push_back(new ViajeEnAuto("Rosario","Paraná",200));
	v.push_back(new ViajeEnAvion("Paraná","Buenos Aires",400));
	v.push_back(new ViajeEnColectivo("Buenos Aires","Rosario",320));
	cout << "Te vas a pasar " << calcTiempoTotal(v) << "hs viajando" << endl;
	for(Viaje *p : v) delete p;
	return 0;
}
