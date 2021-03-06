/* 
* Implementar una función reciba un arreglo de enteros y su tamaño y retorne la suma de los elementos de un arreglo.
* Tamaño del arreglo 1000000. (Iterativa y recursiva). 
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long long sumIterativa (long a[], long tam)
{
    long long suma = 0;
    for (int i = 0; i < tam; i++)
        suma += a[i];        
    return suma;
}

long long sumRecursiva (long a[], long tam, long pos)   // Recorre las posiciones y va sumando valores hasta que sea menor o igual
{
    if (pos < tam){
        cout<< a[pos] <<"-";
        return a[pos] + sumRecursiva( a, tam, ++pos);
    }
    return 0;
}

int main()
{
    // Creación de un array de los 1 000 000 primeros numeros enteros
    long n = 1000000;
    long arrayN[n];
    // arrayN[0]=0;
    for (long i=0; i<n; i++)
        arrayN[i] = i+1;

    cout<<sumIterativa(arrayN, n)<<endl;
    cout<<sumRecursiva(arrayN, n, 0)<<endl;

    return 0;
}