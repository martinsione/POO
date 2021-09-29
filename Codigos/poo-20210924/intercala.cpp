/// Realice una función llamada ...intercala(.....) que recibe como
#include <algorithm>
using namespace std;
/// parámetros 2 punteros a vectores de enteros.
/// La función debe devolver un nuevo vector con los elementos intercalados
/// de los vectores pasados como parámetro.

int *intercala(int *v1, int n1, int *v2, int n2) {
	int *r = new int[n1+n2];
	
	int nmax = max(n1,n2), j=0;
	for (int i=0; i<nmax; ++i) { 
		if (i<n1) { *(r+j) = *(v1+i); ++j; }
		if (i<n2) { *(r+j) = *(v2+i); ++j; }
	}
	
	return r;
}

#include <iostream>
using namespace std;

int main() {
	/// por ejemplo si a=[2,4,5,1,6,3] y b=[10,20]
	int a[] = {2,4,5,1,6,3}, b[] = {10,20};
	int na = 6, nb = 2;
	
	int *r = intercala(a,na, b,nb);
	int nr = na+nb;
	/// se deberá obtener [2,10,4,20,5,1,6,3].
	/// Utilice la función en un programa cliente. 
	for (int i=0; i<nr; ++i)
		cout << *(r+i) << " " << endl;
	
	delete [] r;
}

