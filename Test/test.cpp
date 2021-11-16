#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int n[] = { 1,2,3,4,5,6,7,8 };
    cout << rand()%n[7] << endl;
    for (int numbers : n) {
     cout << rand()%numbers;
     cin.get();
    }


    return 0;
}

