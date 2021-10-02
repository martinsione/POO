#include <iostream>
using namespace std;

int *arregloOrdenado(int *a, int *b) {
  int j = 0;
  do {
    if (*(a + j) < *(a + j + 1)) {
      j++;
    } else {
      int *c;
      c = new int[j + 1];
      for (int i = 0; i < (j + 1); i++)
        c[i] = *(a + i);
      return c;
    }
  } while (a != b);
  return a;
}

int main() {
  int arr_size, *inicio, *fin, n;

  cout << "Ingrese tamaño del arreglo que desea probar: ";
  cin >> arr_size;

  inicio = new int[arr_size];
  *fin = *(inicio + arr_size);

  for (int i = 0; i < arr_size; i++) {
    cout << "Ingrese un numero: ";
    cin >> n;
    *(inicio + i) = n;
  }

  int *nuevoArray = arregloOrdenado(inicio, fin);
  if (*nuevoArray == *inicio)
    cout << "El array estaba ordenado";
  else
    cout << "El arreglo estaba desordenado";

  delete[] inicio;

  return 0;
}
