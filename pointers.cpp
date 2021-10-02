#include <iostream>
#include <iterator>
using namespace std;

int main() {

  int n, *p;
  n = 20;
  p = &n;
  cout << "El puntero p se encuentra en: " << p << endl;
  cout << "El puntero p apunta al valor: " << *p << endl;

  return 0;
}
