///Hecho por Ignacio Andre Nazar | 43755639
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>
using namespace std;

bool es_par(vector<int> v){
	return v.size()%2==0;
}

tuple<float,float> procesa_secuencia(vector<int> &v){
	
	
	float primer_mitad;
	float segunda_mitad;
	
	if(es_par(v)){
		/*
			Si el size es par, entra en el if,ordena la primer mitad del array, luego, ordena desde la mitad +1 hasta el final y despues
			lo da vuelta con reverse.
			Luego calcula la suma total de la primer y segunda mitad;
		*/
		auto it=v.begin()+v.size()/2; /// Por alguna razon no me dejaba hacer (v.size()/2)-1, asi sacar la mitad, esta es la unica forma que me deja.
		sort(v.begin(),it);
		
		sort(it+1,v.end()); 
		reverse(it+1,v.end());
		
		primer_mitad=accumulate(v.begin(),it,0);
		
		segunda_mitad=accumulate(it+1,v.end(),0);
		
	
		
	}else{
		/*
			Si es impar entra en el else, primero calculo la mitad del array, lo elimino con erase y me devuelve el it apuntando a la nueva mitad
			, ordeno de el principio hasta la mitad, y desde la mitad hasta el final y hago reverse. Calculo la suma de las mitades y devuelvo la tupla.
		
			En los dos lados de la condicional me podria haber ahorrado un sort, porque lo tengo que ordenar de todas formas para despues dar vuelta la segunda mitad.
		
		*/
		auto it=v.begin()+v.size()/2;
		it=v.erase(it);
		
		sort(v.begin(),it);
		
		sort(it+1,v.end()); 
		reverse(it+1,v.end());
		
		primer_mitad=accumulate(v.begin(),it,0);
		
		segunda_mitad=accumulate(it+1,v.end(),0);
		
	}
	
	return make_tuple(primer_mitad,segunda_mitad);
}


int main() {
	
	/*
	Inicializo el archivo, un array para guardar los int's y un int para poder leer los datos del archivo txt y le hago push_back al array
	Declaro dos flotantes porque los promedios pueden tener decimales.
	Un iNT W con la mitad -1 del array, muestro en consola la  primer_mitad/w que me devuelve el promedio de esa mitad.
	Y para la segunda, hago segunda_mitad/w+1 porque si no tomaria un elemento de mas.
	Luego muestro los datos del array, cierro el ifstream y abro un ofstream para escribir el nuevo array en el archivo
	*/
	vector<int> v;
	int x;
	ifstream fin("data20211104.txt");
	
	while(fin>>x){
		v.push_back(x);
	}
	
	float primer_mitad,segunda_mitad;
	
	tie(primer_mitad,segunda_mitad)=procesa_secuencia(v);
	
	int w=(v.size()/2)-1;
	cout<<(primer_mitad/w)<<endl;
	
	cout<<(segunda_mitad/(w+1));
	
	for(int &k : v){cout<<k<<endl;}
	
	fin.close();
	
	ofstream fout("data20211104.txt",ios::trunc);
	
	for(size_t i=0;i<v.size();i++) { 
		fout<<v[i]<<endl;
	}
	
	return 0;
}

