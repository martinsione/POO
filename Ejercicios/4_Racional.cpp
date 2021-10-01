#include <iostream>
using namespace std;

class Racional {
    int num, den;
    double frac = double(num)/den;
public:
    Racional(int n, int d) : num(n), den(d) {}
    double VerFrac() { return frac; }
    int operator[](int param) const { return param == 0 ? num : den; }
    int &operator[](int param) { return param == 0 ? num : den; }
};

Racional operator+(Racional x, Racional y) {
    int num = (x[0] * y[1] + y[0] *x[1]);
    int den = (x[1] * y[1]);
    return Racional(num, den);
};

Racional operator*(Racional x, Racional y) {
    int num = x[0] * y[0];
    int den = x[1] * y[1];
    return Racional(num, den);
}

Racional operator*(Racional x, double escalar) {
    int num = x[0] * escalar;
    int den = x[1];
    return Racional(num, den);
}

Racional operator*(double escalar, Racional x) {
    int num = x[0] * escalar;
    int den = x[1];
    return Racional(num, den);
}

Racional operator++(Racional &x) {
    x[0] += x[1];
    return x;
}

Racional operator++(Racional &x, int) {
    Racional aux = Racional(x[0], x[1]);
    x[0] += x[1];
    return aux;
}

bool operator<(Racional x, Racional y)  { return x.VerFrac() < y.VerFrac(); }
bool operator<=(Racional x, Racional y) { return x.VerFrac() <= y.VerFrac(); }
bool operator>(Racional x, Racional y)  { return x.VerFrac() > y.VerFrac(); }
bool operator>=(Racional x, Racional y) { return x.VerFrac() >= y.VerFrac(); }
bool operator==(Racional x, Racional y) { return x.VerFrac() == y.VerFrac(); }
bool operator!=(Racional x, Racional y) { return x.VerFrac() != y.VerFrac(); }


/* istream & operator >> (istream &in,  Complex &c) { */
/*     cout << "Enter Real Part "; */
/*     in >> c.real; */
/*     cout << "Enter Imaginary Part "; */
/*     in >> c.imag; */
/*     return in; */
/* } */

istream &operator>>(istream  &in, Racional p) {
    return in >> p;
}

ostream &operator<<(ostream &out, Racional p) {
    return out << p[0] << '/' << p[1];
};

int main() {
    int aux_num, aux_den;
    cin >> aux_num;
    cin >> aux_den;
    Racional t(aux_num, aux_den);
    cout << "La fraccion " << t << " es aproximadamente " << t.VerFrac() << endl;

    /* Racional x(1, 3), y(7, 6); */
    /* y[0] = 8; */
    /* cout << y[0] << endl; */
    /* cout << x++ << endl; */
    /* cout << ++x << endl; */
    /* cout << (y < x) << endl; */

    return 0;
}

