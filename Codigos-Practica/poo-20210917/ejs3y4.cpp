#include <iostream>
using namespace std;

struct Punto {
	float x,y;
};

bool son_muy_muy_parecidos(float f1, float f2) {
	return abs(f1-f2)<1e-5;
}

class RectaBASE {
public:
	virtual string ObtenerEcuacion() const = 0;
	virtual bool Pertenece(Punto t) const = 0;
	virtual ~RectaBASE() { }
};

void foo(RectaBASE *re) {
	cout << re->ObtenerEcuacion() << endl;
	while(true) {
		Punto t;
		cout << "Ingrese un pto (x e y): ";
		cin >> t.x >> t.y;
		if (re->Pertenece(t)) cout << "Si" << endl; 
		else                  cout << "No" << endl;
	}
}


// y = m*x + b
class RectaExplicita : public RectaBASE {
public:
	RectaExplicita(Punto p, Punto q) {
		m = (q.y-p.y)/(q.x-p.x);
		b = p.y-m*p.x;
	}
	float VerM() const { return m; }
	float VerB() const { return b; }
	string ObtenerEcuacion() const override {
		return "y = " + to_string(m) + "*x + " + to_string(b);
	}
	bool Pertenece(Punto t) const override {
		return son_muy_muy_parecidos(t.y,m*t.x+b);
	}
private:
	float m, b;
};

// a*x + b*y + c = 0
class RectaGeneral : public RectaBASE {
public:
	RectaGeneral(Punto p, Punto q) {
		a = q.y - p.y;
		b = p.x - q.x;
		c = -a*p.x -b*p.y;
	}
	float VerA() const { return a; }
	float VerB() const { return b; }
	float VerC() const { return c; }
	string ObtenerEcuacion() const override {
		return to_string(a) + "*x + " + to_string(b) + "*y + " 
			   + to_string(c) + " = 0";
	}
	bool Pertenece(Punto t) const override {
		return son_muy_muy_parecidos(a*t.x + b*t.y + c, 0.0);
	}
private:
	float a,b,c;
};


int main() {
	Punto p = {1,1}, q = {3,2}; // y = 1x+0
	
	cout << "1-general, 2-explicita ? ";
	int cual; cin >> cual;
	
	RectaBASE *re;
	if (cual==1) {
		re = new RectaGeneral(p,q);
	} else {
		re = new RectaExplicita(p,q);
	}
	
	foo(re);
	
	delete re; 
	return 0;
}

