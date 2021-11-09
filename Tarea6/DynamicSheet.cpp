#include "DynamicSheet.hpp"
//Francisco Alonso Torres Rosa - 00046821
int menu(){
    system("CLS");
    int opcion = 0;
    cout << "\nHoja Electronica - EXCEL CHAFA";
    cout << endl << "1) Agregar una celda a la hoja Electronica." << endl;
    cout << "2) Mostrar Hoja Electronica." << endl;
    cout << "3) Calcular la suma de una Fila de la Hoja Electronica." << endl;
    cout << "4) Calcular la suma de una Columna de la Hoja Electronica." << endl;
    cout << "5) Eliminar una celda de la Hoja Electronica." << endl;
    cout << "6) Salir del programa" << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main()
{
    Node aux;
    int m, n, i, j;
    cout << "Ingrese las dimensiones de la Hoja Electronica a crear." << endl;
    cout << "Numero de filas: "; cin >> m;
    cout << "Numero de columnas: "; cin >> n;

    DynamicSheet PAGE1(m, n);
    bool continuar = true;
    string Enter;

    do{
        switch(menu()){
            case 1:
                system("CLS");
                aux = giveData();
                PAGE1.addNode( aux.nRow, aux.nColumn, aux.DATA );
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 2:
                system("CLS");
                PAGE1.printAll();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 3:
                system("CLS");
                cout << "Ingrese el numero de la fila: "; cin >> i;
                cin.ignore();
                PAGE1.sumRows(i);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 4:
                system("CLS");
                cout << "Ingrese el numero de la columna: "; cin >> i;
                cin.ignore();
                PAGE1.sumColumns(i);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 5:
                system("CLS");
                cout << "Ingrese el numero de la fila: "; cin >> i;
                cout << "Ingrese el numero de la columna: "; cin >> j;
                cin.ignore();
                PAGE1.deleteNode(i, j);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 6:
                continuar = false;
                break;

            default:
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    return 0;
};
