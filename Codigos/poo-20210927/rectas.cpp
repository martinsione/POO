#include <iostream>
using namespace std;

struct Punto { float x,y; };


bool son_muy_muy_parecidos(float a, float b) {
	return abs(a-b)<1e-5;
}

class Recta {
public:
	virtual string VerEcuacion() const = 0;
	virtual bool Pertenece(Punto p) const = 0;
	virtual ~Recta() { }
};
void usarRectaParaAlgoInteresante(Recta &r) {
	cout << r.VerEcuacion() << endl;
	Punto p; cin >> p.x >> p.y;
	if (r.Pertenece(p)) cout << "Si"; else cout << "No";
}




class RectaExplicita : public Recta { // y=m*x+b
	float m,b;
public:
	RectaExplicita(Punto p1, Punto p2) {
		m = (p2.y-p1.y) / (p2.x-p1.x);
		b = p1.y-m*p1.x;
	}
	float VerM() const { return m; }
	float VerB() const { return b; }
	string VerEcuacion() const override {
		return "y = " + to_string(m) + "*x + " + to_string(b);
	}
	bool Pertenece(Punto p) const override {
		return son_muy_muy_parecidos(p.y,m*p.x+b);
	}
};
class RectaGeneral : public Recta { // a*x+b*y+c=0
	float a,b,c;
public:
	RectaGeneral(Punto p1, Punto p2) {
		a = p2.y-p1.y;
		b = p1.x-p2.x;
		c = -a*p1.x-b*p1.y;
	}
	float VerA() const { return a; }
	float VerB() const { return b; }
	float VerC() const { return c; }
	string VerEcuacion() const override {
		return to_string(a) + "*x + " + to_string(b) + "*y + " + to_string(c) + " = 0";
	}
	bool Pertenece(Punto p) const override {
		return son_muy_muy_parecidos(a*p.x+b*p.y+c,0.0);
	}
};

int main() {
	
	Recta *r;
	Punto p1 = {1,2}, p2 = {2,3};
	cout << "1- explicita, 2 - general ? ";
	int x; cin >> x;
	if (x==1) r = new RectaExplicita(p1,p2);
	else      r = new RectaGeneral(p1,p2);
		
	usarRectaParaAlgoInteresante(*r);
	
	delete r;
}

