#include "BinarySearchTree.hpp"

int menu(){
    system("CLS");
    int opcion = 0;
    cout << "\n*********** Arbol Binario de Busqueda - ABB - Binary Search Tree - BST ***********\n";
    cout << "1) Agregar un elemento Entero a el arbol binario." << endl;
    cout << "2) Mostrar el arbol binario." << endl;
    cout << "3) Eliminar un elemento a el arbol binario, forma propia con puntero FATHER." << endl;
    cout << "4) Eliminar un elemento a el arbol binario, forma ING Guillermo." << endl;

    cout << "5) Mostrar el arbol binario en InOrden." << endl;
    cout << "6) Mostrar el arbol binario en PreOrden." << endl;
    cout << "7) Mostrar el arbol binario en PostOrden." << endl;
    cout << "8) Agregar una lista de elementos preseleccionados a el arbol binario." << endl;
    cout << "9) Salir del programa" << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(){

    BST myTree;
    int aux;

    bool continuar = true;

    string Enter;

    do{
        switch(menu()){
            case 1:
                system("CLS");
                cout << "Ingrese el Entero para agregarlo a el arbol: ";
                cin >> aux;
                myTree.addNode( myTree.getpBST() , aux, NULL);
                cin.ignore();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 2:
                system("CLS");
                if(myTree.getpBST() == NULL ){
                    cout << "El arbol esta vacio." << endl;
                }
                else{
                    cout << "\n\n***************Arbol Binario de Busqueda***************\n";
                    myTree.printFullTree( myTree.getpBST(), 0);
                }
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 3:
                system("CLS");
                if(myTree.getpBST() == NULL ){
                    cout << "El arbol esta vacio." << endl;
                }
                else{
                    cout << "Ingrese el Entero a buscar para eliminarlo de el arbol: ";
                    cin >> aux;
                    myTree.search_DeleteNode( myTree.getpBST(), aux);
                    cin.ignore();
                }
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 4:
                system("CLS");
                if(myTree.getpBST() == NULL ){
                    cout << "El arbol esta vacio." << endl;
                }
                else{
                    cout << "Ingrese el Entero a buscar para eliminarlo de el arbol: ";
                    cin >> aux;
                    myTree.search_DeleteNode_2(aux);
                    cin.ignore();
                }
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 5:
                system("CLS");
                myTree.printInorder();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 6:
                system("CLS");
                myTree.printPreorder();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 7:
                system("CLS");
                myTree.printPostorder();
                cout << "Presione ENTER para continuar..."; getline(cin,Enter);
                break;

            case 8:
                system("CLS");
                myTree.addNode( myTree.getpBST()  , 53, NULL);
                myTree.addNode( myTree.getpBST()  , 434, NULL);
                myTree.addNode( myTree.getpBST()  , 16, NULL);
                myTree.addNode( myTree.getpBST()  , 11, NULL);
                myTree.addNode( myTree.getpBST()  , 45, NULL);
                myTree.addNode( myTree.getpBST()  , 56, NULL);
                myTree.addNode( myTree.getpBST()  , 62, NULL);
                myTree.addNode( myTree.getpBST()  ,51, NULL);
                myTree.addNode( myTree.getpBST()  , 55, NULL);
                myTree.addNode( myTree.getpBST()  , 74, NULL);
                myTree.addNode( myTree.getpBST()  , 75, NULL);
                myTree.addNode( myTree.getpBST()  , 76, NULL);
                myTree.addNode( myTree.getpBST()  , 68, NULL);
                myTree.addNode( myTree.getpBST()  , 131, NULL);
                myTree.addNode( myTree.getpBST()  , 35, NULL);

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
}