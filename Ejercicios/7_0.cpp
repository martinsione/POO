#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T buscar_menor(const vector<T> &v) {
    T men = v[0];

    for (size_t i=0; i<v.size(); i++)
        if (v[i] < men) 
            men = v[i];

    return men;
}


int main() {
    vector<float>v = {1, 423, 43, 5, 6, 0, -423};
    /* float men = buscar_menor<float>(v); */
    float men = buscar_menor(v);
    cout << men;

    return 0;
}
