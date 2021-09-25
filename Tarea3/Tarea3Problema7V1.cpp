#include<iostream>
#include<string>
// FRANCISCO ALONSO TORRES ROSA 00046821 - Tarea3 Problema7

using namespace std;

struct Node{
    int data;
    Node *next;
};

class Pile{
    private:
        Node *head;
        
    public:
        Pile();
        Pile(int);
        void push(int);
        void push(Node *);
        void print();
        Node *pop();
};

Pile::Pile(){
    head = NULL;
}

Pile::Pile(int P){
    head = NULL;
    push(P);
}

void Pile::push(int P){
    Node *temp = new Node;
    temp->data = P;
    temp->next = head;
    head = temp;
}

void Pile::push(Node *P){
    P->next = head;
    head = P;
}

Node *Pile::pop(){
    if(head){
        Node *s = new Node;
        s = head;
        head = head->next;
        return s;
    }
    cout << "Pila vacia" << endl;
    return NULL;
}

void Pile::print(){
    Node *p = head;
    while(p){
        cout << "Valor: "<< p->data << endl;
        p = p->next;
    }
    delete p;
}

void oddOrEven(Pile *P1, Pile *P2, Pile *P3){
    Node *aux;
    aux = P1->pop();
    if(aux){
        if(aux->data %2 == 0) {
            P2->push(aux);
	        cout << "Moviendo " << aux->data << " a la pila de los pares\n";
        }
        else{
            P3->push(aux);
	        cout << "Moviendo " << aux->data << " a la pila de los impares\n";
        }
        oddOrEven(P1, P2, P3);
    }
}

int menu(){
    int option;
    system("CLS");
    cout << "\n******************Programa para ordenar pila de numeros pares e impares******************" << endl;
    cout << "1- Agregar un nuevo numero a la pila principal\n";
    cout << "2- Separar pares e impares de pila principal en 2 pilas distintas\n";
    cout << "3- Mostrar la pila de numeros principales\n";
    cout << "4- Mostrar la pila de numeros pares\n";
    cout << "5- Mostrar la pila de numeros impares\n";
    cout << "6- Salir del programa\n";
    cout << "Opcion: "; cin >> option;
    cin.ignore();
    cout << endl;
    return option;
}

int main(){
    bool loop = true;
    string Enter;
    int value;

    Pile mainPile;
    Pile oddPile;
    Pile evenPile;

    do
    {
        switch (menu())
        {
        case 1:
            system("CLS");
            cout << "Valor: "; cin >> value; 
            while(value<1){ //Rango de los Naturales
                cout << "Ingrese un numero valido en el rango de los Naturales\n"; cin >> value;
            }
            cout << endl;
            mainPile.push(value);
            break;
            
        case 2:
            system("CLS");
            oddOrEven(&mainPile, &evenPile, &oddPile);
            cout << endl;
            cout << "Presione ENTER para continuar..."; getline(cin,Enter);
            break;

        case 3:
            system("CLS");
            cout << "**********Pila principal**********" << endl; 
            mainPile.print();
            cout << "Presione ENTER para continuar..."; getline(cin,Enter);
            break;

        case 4:
            system("CLS");
            cout << "**********Pila de pares**********" << endl; 
            evenPile.print();
            cout << "Presione ENTER para continuar..."; getline(cin,Enter);
            break;

        case 5:
            system("CLS");
            cout << "**********Pila de impares**********" << endl; 
            oddPile.print();
            cout << "Presione ENTER para continuar..."; getline(cin,Enter);
            break;

        case 6:
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
