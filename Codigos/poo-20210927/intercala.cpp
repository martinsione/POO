#include <iostream>
using namespace std;

int *intercala(int *v1, int n1, int *v2, int n2) {
	int *v = new int[n1+n2];
	
	int nmax = max(n1,n2), j = 0;
	for (int i=0; i<nmax; ++i) { 
		if (i<n1) { *(v+j) = *(v1+i); ++j; }
		if (i<n2) { *(v+j) = *(v2+i); ++j; }
	}
	
	return v;
}

int main() {
	int v1[] = {1,3,5,7,9};
	int v2[] = {2,4,6};
	
	int n1 = 5, n2 = 3;
	int *v = intercala(v1,n1, v2,n2);
	
	int n = n1+n2;
	for (int i=0; i<n; ++i) 
		cout << *(v+i) << " ";
	
	delete [] v;
}

