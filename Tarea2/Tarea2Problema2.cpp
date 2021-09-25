#include<iostream>
using namespace std;
//FRANCISCO ALONSO TORRES ROSA 00046821 -TAREA2 PROBLEMA 2
void count(int, int);

int main(){
    int num;
    cout << "Escalera Recursiva" << endl;
    cout << "Ingrese un numero para realizar una escalera ascendente y descendente: ";
    cin >> num;
    count(num,num);
    return 0;
}

void count(int a, int b){ /*Utilizamos una variable auxiliar "b",
                        para poder conservar el varlor original ingresado, 
                        asi que solo utilizaremos una de estas variables a la vez*/

    if(0<a && a==b) { /*Bloque que da inicio a la llamada del conteo regresivo de "a",
                        para evitar recursiones no deseadas,
                        esto solo sucede si "a" tiene el mismo valor que "b"*/

        count(a-1,b); //llamada recursiva disminuyendo "a", pero conservando su valor en "b".

        cout << a << endl; //cuando termine el despliegue [1,a-1], se desplegara "a".
    }

    if(0<a && a<b) { //Bloque de recursion a realizar en el intervalo [1,a-1]

        count(a-1,b); // llamada recursiva disminuyendo "a", pero conservando su valor en "b".

        cout << a << endl; //despliegue del intervalo [1,a-1]
    }

    /*Mientras "a" no contenga el mismo valor de "b", y los 2 if anteriores no tengan finalizadas
    sus recursiones, los 2 if siguientes no seran realizados*/

    if(0<b && b==a) { /*Bloque que da inicio a la llamada del conteo regresivo de "b",
                        para evitar recursiones no deseadas,
                        esto solo sucede si "b" tiene el mismo valor que "a"*/

        count(a,b-1); //llamada recursiva disminuyendo "b", pero conservando su valor en "a".
    }

    if(0<b && b<a) { //Bloque de recursion a realizar en el intervalo [b-1,1]

        cout << b << endl; //despliegue del intervalo [b-1,1]

        count(a,b-1); // llamada recursiva disminuyendo "b", pero conservando su valor en "a".
    }
}