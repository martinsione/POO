#include <cstdio>
#include <iostream>
using namespace std;

class Vector {
    public:
        Vector(int size) {
            m_pointer = new int[size];
            m_size = size;
        }
        ~Vector () {
            delete m_pointer;
        }
        int size() {
            return m_size;
        }
        void push(int number) {
        }

    private:
        int *m_pointer;
        int m_size;
};

int main() {
    Vector v(3);
    cout << v.size() << endl;
    v.push(3);

    return 0;
}
