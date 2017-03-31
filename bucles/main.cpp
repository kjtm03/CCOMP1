#include <iostream>

using namespace std;

int main()
{
    /*
    int arreglo[4];
    int temp1,temp2;

    cout << "Ingrese el valor de la primera posicion: " << endl;
    cin >> arreglo[0];
    cout << "Ingrese el valor de la segunda posicion: " << endl;
    cin >> arreglo[1];
    cout << "Ingrese el valode de la tercera posicion: " << endl;
    cin >> arreglo[2];
    cout << "Ingrese el valor de la cuarta posicion: " << endl;
    cin >> arreglo[3];

    temp1 = arreglo [0];
    arreglo [0] = arreglo [3];
    arreglo [3] = temp1;

    temp2 = arreglo [1];
    arreglo [1] = arreglo [2];
    arreglo [2] = temp2;

    cout << arreglo[0] << endl;
    cout << arreglo[1] << endl;
    cout << arreglo[2] << endl;
    cout << arreglo[3] << endl;
    <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      int arreglo[4];
    int tam;
    cin >> tam;
    int p;
    for (int i=0; i < (tam/2); i++){
        p = arreglo[i];
        arreglo[i] = arreglo [tam-1-i];
        arreglo[tam-1-i] = p;
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/
    int arreglo[4];
    int temp1;
    int a;

    cout << "Ingresa el tamaño del arreglo: " <<endl;
    cin >> a;
    for (int i = 0; i < x; i++)
        cin >> arreglo[i];

    for (i=0; i<a ;i++){
        temp1 = arreglo[a];
        arreglo[a] = arreglo[a-1-i];
        arreglo[a-1-i] = temp1;
    }



    }


