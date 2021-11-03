#include "Tarea 5.hpp""

int menu(){
    system("CLS");
    int opcion = 0;
    cout << "\nPrograma de Registro Veterinario";
    cout << endl << "1) Agregar una mascota al principio de la lista." << endl;
    cout << "2) Agregar una mascota al final de la lista." << endl;
    cout << "3) Agregar una mascota ascendentemente segun la edad." << endl;
    cout << "4) Mostrar lista de mascotas desde el inicio." << endl;
    cout << "5) Mostrar lista de mascotas desde el final." << endl;
    cout << "6) Buscar mascota por id en la lista." << endl;
    cout << "7) Borrar una mascota por id." << endl;
    cout << "8) Destruir lista de mascotas." << endl;
    cout << "9) Salir del programa" << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main()
{
    Elements_Data aux;
    CircularSinglyLinkedList LIST;
    bool continuar = true;
    string Enter;

    do{
        switch(menu()){
            case 1:
                system("CLS");
                aux = giveData();
                LIST.addFront(aux);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 2:
                system("CLS");
                aux = giveData();
                LIST.addBack(aux);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 3:
                system("CLS");
                aux = giveData();
                LIST.addAscending(aux);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 4:
                system("CLS");
                LIST.printForward();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 5:
                system("CLS");
                LIST.printReverse();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 6:
                system("CLS");
                cout << "Ingrese un id para buscar: "; getline(cin, aux.id);
                LIST.searchById(aux.id);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 7:
                system("CLS");
                cout << "Ingrese un id para buscar: "; getline(cin, aux.id);
                LIST.deleteById(aux.id);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 8:
                system("CLS");
                LIST.~CircularSinglyLinkedList();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 9:
                continuar = false;
                break;

            default:
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    return 0;
};

