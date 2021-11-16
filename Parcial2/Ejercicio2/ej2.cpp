#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Producto {
  int codigo, stock;
  float precio;
  string desc;
};

struct Detalle {
    int fecha, codigo_producto, codigo_cliente, cantidad;
};

void actualizar_ventas(int dni, int fecha, vector<int>codigo_producto, vector<int>cantidades) {
    // Detalle
    ofstream ventas("ventas.dat", ios::binary|ios::app);
    Detalle producto;
    producto.codigo_cliente = dni;
    producto.fecha = fecha;
    for (size_t i=0; i<codigo_producto.size(); i++) {
        producto.codigo_producto = codigo_producto[i];
        producto.cantidad = cantidades[i];
        ventas.write(reinterpret_cast<char*>(&producto), sizeof(producto));
    }

    // Producto
    fstream productos("productos.dat", ios::binary|ios::in|ios::ate);
    int n = productos.seekg()/sizeof(Producto);
    Producto p;
    for (size_t i=0; i<n; i++) {
        productos.read(reinterpret_cast<char*>(&p), sizeof(p));
        for (size_t j=0; j<codigo_producto.size(); i++) {
            if (p.codigo == codigo_producto[j]) {
                productos.seekp(j * sizeof(Producto));
                p.stock -= cantidades[i];
                productos.write(reinterpret_cast<char*>(&p),sizeof(p))
            }
        }
    }
}

int main() {

    return 0;
}

