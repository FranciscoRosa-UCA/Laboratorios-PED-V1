#include "Tarea 4.hpp"

Elements_Data giveData(){
    Elements_Data dt;
    cout << "Nombre: "; getline(cin, dt.name);
    cout << "id: "; getline(cin, dt.id);
    cout << "Profile: "; getline(cin, dt.profile);
    return dt;
}

void showData(Elements_Data dt){
        cout << "Nombre: " << dt.name << endl;
        cout << "id: "<< dt.id << endl;
        cout << "Perfil: " << dt.profile << endl;
        cout << endl;
}

int menu(){
    system("CLS");
    int opcion = 0;
    cout << "\nPrograma de Registro de Personal administrativo";
    cout << endl << "1) Agregar persona al principio de la lista." << endl;
    cout << "2) Agregar persona al final de la lista." << endl;
    cout << "3) Mostrar lista desde el inicio." << endl;
    cout << "4) Mostrar lista desde el final." << endl;
    cout << "5) Mostrar el HEADER." << endl;
    cout << "6) Mostrar el TRAILER." << endl;
    cout << "7) Eliminar la primera persona de la lista." << endl;
    cout << "8) Eliminar la ultima persona de la lista." << endl;
    cout << "9) Salir del programa" << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main()
{
    Elements_Data aux={"xd","xd","xd"};
    LinkedList ll;
    bool continuar = true;
    string Enter;

    do{
        switch(menu()){
            case 1:
                system("CLS");
                aux = giveData();
                ll.addFront(aux);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 2:
                system("CLS");
                aux = giveData();
                ll.addBack(aux);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 3:
                system("CLS");
                ll.printForward();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 4:
                system("CLS");
                ll.printReverse();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 5:
                system("CLS");
                aux = ll.getFront();
                showData(aux);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 6:
                system("CLS");
                aux = ll.getBack();
                showData(aux);
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 7:
                system("CLS");
                ll.removeFront();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 8:
                system("CLS");
                ll.removeBack();
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

