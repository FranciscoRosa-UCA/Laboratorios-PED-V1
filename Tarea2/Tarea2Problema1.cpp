#include<iostream>
using namespace std;
//FRANCISCO ALONSO TORRES ROSA 00046821 -TAREA2 PROBLEMA 1
int mcdEuclides(int, int);

int main(){
    int a,b;
    cout << "Calcular el MCD de 2 numeros" << endl;
    cout << "Ingrese el valor del primer numero: "; cin >> a;
    cout << "Ingrese el valor del segundo numero: "; cin >> b;
    cout << "MCD(" << a << "," << b << ")= " << mcdEuclides(a,b) << endl;
    return 0;
}

int mcdEuclides(int mayor, int menor){

    if (menor==0) return mayor; /*Hasta que en algun llamado de la funcion "menor" sea igual a 0,
                                automaticamente el mcd sera "mayor"*/

    return mcdEuclides(menor, mayor%menor); /*se intercambiara "mayor con menor" y "menor con mayor%menor",
                                            Esta recursion se realizara simpre hasta
                                            que "menor" sea igual CERO*/
}
