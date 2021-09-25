#include<iostream>
#include<string>
// FRANCISCO ALONSO TORRES ROSA 00046821 LABORATORIO #1

using namespace std;

struct Student{
    int age;
    int phone;
    string id;
    string name;
    string last_name;
    string email;
};

struct Node{
    Student data;
    Node *next;
};

class LinkedList{
    public:
        Node *head;

        LinkedList(){
            head = nullptr;
        }
        LinkedList(int, int, string, string, string, string);
        void push(int, int, string, string, string, string);
        void pushEnd(int, int, string, string, string, string);
        void print();
        Node *reverse(Node *);
        void reverseIt();
        bool deleteNode(string);
};

LinkedList::LinkedList(int P1, int P2, string P3, string P4, string P5, string P6){
    head = nullptr;
    push(P1,P2,P3,P4,P5,P6);
}

void LinkedList::push(int P1, int P2, string P3, string P4, string P5, string P6){
    Node *temp = new Node;
    temp->data.age = P1;
    temp->data.phone = P2;
    temp->data.id = P3;
    temp->data.name = P4;
    temp->data.last_name = P5;
    temp->data.email = P6;

    temp->next = head;
    head = temp;
}

void LinkedList::pushEnd(int P1, int P2, string P3, string P4, string P5, string P6){
    Node *temp = new Node;
    temp->data.age = P1;
    temp->data.phone = P2;
    temp->data.id = P3;
    temp->data.name = P4;
    temp->data.last_name = P5;
    temp->data.email = P6;

    temp->next = NULL;

    if(!head)
        head = temp;
    else{
        Node *p;
        p = head;
        while(p->next){
            p = p->next;
        }
        p->next = temp;
    }

}

void LinkedList::print(){
    Node *p = head;
    while(p){
        cout << "Carnet: "<< p->data.id << endl;
        cout << "Nombres: "<< p->data.name << endl;
        cout << "Apellidos: "<< p->data.last_name << endl;
        cout << "Edad: " << p->data.age << " years" << endl;
        cout << "Numero de telefono: +503 " << p->data.phone << endl;
        cout << "Correo electronico: " << p->data.email << endl << endl;

        p = p->next;
    }
}

Node *LinkedList::reverse(Node *head){
    if(head == nullptr || head->next == nullptr)
        return head;
    Node *rest = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return rest;
}

void LinkedList::reverseIt(){ // lo mismo que reverse pero de forma Iterativa.

    Node *current = head, *prev = NULL, *next = NULL; /*creacion de 3 punteros Node auxiliares, nombrados convenientemente.
                                                        current sera una copia de head para no perder referencia de head;
                                                        prev y next se inizializaran en null ya que luego los utilizaremos
                                                        y los necesitamos limpios.*/

    while (current){ // mientras current no sea NULL, este seguira realizando las instrucciones

        next = current->next; //next toma la direccion a la que apunta current.

        current->next = prev; /*aqui comenzamos a invertir el orden de la lista,
                                hacemos que la direccion a la que apunta current ahora sea prev,
                                al inicio sera NULL, pero luego de las repeticiones este sera
                                la direccion que prev tomo de current.*/

        prev = current; //el puntero prev hace una copia de current para no perder referencia de el luego que tome la de next.

        current = next; //el puntero current hace una copia de next para no perder referencia de el luego que tome avance una posicion en el bucle.
    }
    head = prev; // el nuevo head ahora apuntara a el ultimo elemento analizado en el bucle, el cual fue prev, ya que current y next ahora apuntan a NULL.
}

bool LinkedList::deleteNode(string D){ /*Esta funcion debe recibir un tipo de dato para poder compararlo
                                        con algun dato existente dentro de alguno de los nodos, si lo encuentra,
                                        sera eliminado y retornara 1, sino retornara 0*/

    if(!head){  // Inicialmente tenemos que analizar que el punterro cabeza no sea null, si no, retornara false ya que no hay nada que analizar
        
        return false;
    }
    else{
        Node *temp = head, *p; /*Utilizaremos 2 punteros auxiliares, donde temp hara una copia de head para no perder referencia de la cabeza.
                                p se utilizara para eliminar el nodo que buscamos*/

        if(temp->data.id == D){ /*Si el dato del nodo de la direccion a la que apunta temp, que actualmente esta en la direccion cabeza,
                                    es igual al dato buscado, entonces realizamos las instrucciones de borrado siguientes*/
            
            head = head->next; // ya que resulto que head era el nodo que contenia el dato a borrar, entonces head debera apuntar a la siguiente direccion.
            
            delete temp; //ya que temp apunta a donde apuntaba head, y head perdio referencia de este nodo, entonces solo queda borrar temp, para limpiar memoria;
            
            return true;
        }
        else{ //En caso de no ser el primer nodo, se realiza lo siguiente

            while(temp->next && temp->next->data.id != D){ /*mientras el nodo de la direccion a la que apunta temp sea distinta de NULL,
                                                            o bien, mientras el dato del nodo de la direccion a la que apunta temp, sea diferente
                                                            de el dato que se esta buscando, realizara lo siguiente*/

                temp = temp->next;  //temp avanzara a la siguiente direccion de memoria.
            }
            if(!temp->next){ //si la direccion a la que apunta temp es NULL entonces retornara false, por que el dato no existe en ningun nodo.
                return false;
            }
            else{ // Si el dato buscado, fue encontrado en algun nodo, se realizara lo siguiente.

                p = temp->next; //El puntero p tomara la direccion del nodo a la que punta temp

                temp->next = temp->next->next; //la direccion a la que apunta temp en este momento, sera sustituida por la siguiente
                
                delete p; //ya que p apunta a donde apuntaba temp, y temp perdio referencia de este nodo, entonces solo queda borrar p, para limpiar memoria;
                
                return true;
            }
        }
        
    }
}