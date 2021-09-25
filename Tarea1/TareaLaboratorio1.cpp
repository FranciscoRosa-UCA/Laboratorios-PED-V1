#include "TareaLaboratorio1.hpp"
// FRANCISCO ALONSO TORRES ROSA 00046821 LABORATORIO #1
int menu(){
    int option;
    system("CLS");
    cout << "\n******************Programa para administrar estudiantes******************" << endl;
    cout << "1- Agregar un nuevo estudiante al INICIO de la lista \n";
    cout << "2- Agregar un nuevo estudiante al FINAL de la lista \n";
    cout << "3- Mostrar la lista de estudiantes\n";
    cout << "4- Eliminar un estudiante de la lista \n";
    cout << "5- Invertir la lista de estudiantes RECURSIVAMENTE\n";
    cout << "6- Invertir la lista de estudiantes ITERATIVAMENTE\n";
    cout << "7- Salir del programa\n";
    cout << "Opcion: "; cin >> option;
    cin.ignore();
    cout << endl;
    return option;
}

int main(){
    bool loop = true;
    string Enter;

    int age;
    int phone;
    string id;
    string name;
    string last_name;
    string email;

    LinkedList LIST(18,11235813,"00046821","Francisco Alonso","Torres Rosa","00046821@uca.edu.sv");

    do
    {
        switch (menu())
        {
        case 1:
            system("CLS");
            cout << "Ingrese los datos para agregar aun nuevo estudiante" << endl;
            cout << "Carnet: "; getline(cin,id);
            cout << "Nombres: "; getline(cin,name);
            cout << "Apellidos: "; getline(cin,last_name);
            cout << "Edad: "; cin >> age; 
            while(age<15 or 120<age){ //Rango inventado
                cout << "Ingrese un numero valido en el rango [15,120]\n"; cin >> age;
            }
            cin.ignore();
            cout << "Correo electronico: "; getline(cin,email);
            cout << "Ingrese un numero de telefono: +503 "; cin >> phone;
            cin.ignore();
            cout << endl;
            LIST.push(age,phone,id,name,last_name,email);
            break;
        
        case 2:
            system("CLS");
            cout << "Ingrese los datos para agregar aun nuevo estudiante" << endl;
            cout << "Carnet: "; getline(cin,id);
            cout << "Nombres: "; getline(cin,name);
            cout << "Apellidos: "; getline(cin,last_name);
            cout << "Correo electronico: "; getline(cin,email);
            cout << "Edad: "; cin >> age; 
            while(age<15 or 120<age){ //Rango inventado
                cout << "Ingrese un numero valido en el rango [15,120]\n"; cin >> age;
            }
            cin.ignore();
            cout << "Ingrese un numero de telefono: +503 "; cin >> phone;
            cin.ignore();
            cout << endl;
            LIST.pushEnd(age,phone,id,name,last_name,email);
            break;

        case 3:
            system("CLS");
            cout << "**********Lista de estudiantes**********" << endl; 
            LIST.print();
            cout << "Presione ENTER para continuar..."; getline(cin,Enter);
            break;

        case 4:
            system("CLS");
            cout << "Ingrese el CARNET de el estudiante desea eliminar: "; getline(cin,id);
            if(LIST.deleteNode(id)) cout << "\nEliminado correctamente" << endl << endl;
            else cout << "\nCarnet no encontrado" << endl << endl;
            cout << "Presione ENTER para continuar..."; getline(cin,Enter);
            break;

        case 5:
            system("CLS");
            LIST.head = LIST.reverse(LIST.head);
            cout <<"Lista invertida exitosamente\n" << endl;
            cout << "Presione ENTER para continuar..."; getline(cin,Enter);
            break;

        case 6:
            system("CLS");
            LIST.reverseIt();
            cout <<"Lista invertida exitosamente\n" << endl;
            cout << "Presione ENTER para continuar..."; getline(cin,Enter);
            break;

        case 7:
            loop = false;
            break;
        
        default:
            system("ClS");
            cout << "Opcion invalida" << endl;
            cout << "Presione ENTER para continuar..."; getline(cin,Enter);
            break;
        }
    } while (loop);
    
    return 0;
}