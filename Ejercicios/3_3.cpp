#include <iostream>
using namespace std;

struct Punto { 
    float x, y; 
};

// y = mx + b
class RectaExplicita {
    public:
        RectaExplicita(Punto p, Punto q) {
            m = (q.y - p.y) / (q.x - p.x);
            b = p.y - (m * p.x);
        }
        string obtenerEcuacion() {
            return "y =" + to_string(m) + "x + " + to_string(b);
        }
        float verM() { return m; }
        float verB() { return b; }
    private:
        float m, b;
};

int main() {
    Punto p = {1, 3}, q = {4, 5};
    RectaExplicita r(p, q);

    cout << r.obtenerEcuacion() << endl;

    return 0;
}

