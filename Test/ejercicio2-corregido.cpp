///Hecho por Ignacio Andre Nazar | 43755639
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

/*
Declaro 3 structs, 2 pedidos por el problema y otro para facilitarme la resolucion y escribir menos codigo.
*/

struct Fecha{
	int dia,mes,anio;
};

struct Producto{
	int codigo;
	float precio;
	string descripcion;
	int stock;
};

struct Detalle{
	Fecha f;
	int codigo_cliente;
	int codigo_producto;
	int unidades_compro;
};

/*
La funcion tiene que registrar la venta en ventas.dat -> Agregar un detalle por cada venta.
Y buscar en el archi productor segun el cod de prodcuto y restar el stock
*/



void actualizarVentas(int dni_cliente,Fecha f1,vector<int>v_codigos, vector<int> v_cantidades){
	ofstream fout("ventas.dat",ios::binary|ios::ate);
	/*
		Abro el archivo dat al final para poder escribir, declaro un detalle, guardo la fecha y el dni cliente
		, escribo al final de todo las nuevas ventas.
		
	*/
	Detalle d;
	d.f=f1;
	d.codigo_cliente=dni_cliente;
	
	for(int i=0;i<v_codigos.size();i++) { 
		d.codigo_producto=v_codigos[i];
		d.unidades_compro=v_cantidades[i];
		fout.write(reinterpret_cast<char*>(&d),sizeof(d));
	}
	
	fout.close();
	
	/*
		Cierro la escritura, declaro un array y un Producto, declaro un ifstream y abro productos dat para descontar el stock, leo el archivo y push_backeo el array
	*/
	vector<Producto> v_p;
	Producto p;
	ifstream fin("producos.dat",ios::binary);

		while(fin.read(reinterpret_cast<char*>(&p),sizeof(p))){
			v_p.push_back(p);
		}
		
		/*
			Se para en una pos del v_p, busca en todo el array v_codigos y lo compara, si no, avanza una pos de v_p y repite,
			Si son iguales los codigos, resta las compras del stock.
		*/
		
		for(int i=0;i<v_codigos.size();i++) {
			for(int j=0;j<v_codigos.size();j++) { 
				if(v_p[i].codigo==v_codigos[j]){
				v_p[i].stock-=v_cantidades[j];
				}
			}
		}
		fin.close();
		
		/*
		Cerre la lectura y nuevamente escribo, borro todo el archivo y lo escribo con los nuevos datos del array
		*/
		ofstream fo("productos.dat",ios::binary|ios::trunc);
		
		for(int i=0;i<v_p.size();i++) { 
			fo.write(reinterpret_cast<char*>(&v_p[i]),sizeof(p));
		}
	
}

int main() {
	
	
	
	
	return 0;
}

