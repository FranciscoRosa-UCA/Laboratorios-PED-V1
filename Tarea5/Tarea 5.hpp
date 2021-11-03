#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Elements_Data
{
    int age;
    int weight;
    string id;
    string owner_name;
    string pet_breed;
};

Elements_Data giveData(){
    Elements_Data dt;
    cout << "owner's name: "; getline(cin, dt.owner_name);
    cout << "id: "; getline(cin, dt.id);
    cout << "raza de la mascota: "; getline(cin, dt.pet_breed);
    cout << "peso de la mascota (kg): "; cin >> dt.weight;
    while(dt.weight <= 0){
        cout << "ingrese un peso valido, debe ser mayor que CERO" << endl;
        cout << "peso de la mascota (kg): "; cin >> dt.weight;
    }
    cout << "edad de la mascota: "; cin >> dt.age;
    while(dt.age <= 0){
        cout << "ingrese una edad valida, debe ser mayor que CERO" << endl;
        cout << "edad de la mascota: "; cin >> dt.age;
    }
    cin.ignore();
    return dt;
}

void showData(Elements_Data dt){
    cout << "owner's name: " << dt.owner_name << endl;
    cout << "id: " << dt.id << endl;
    cout << "raza de la mascota: " << dt.pet_breed<< endl;
    cout << "peso de la mascota: " << dt.weight << "kg" << endl;
    cout << "edad de la mascota: " << dt.age << endl;
    cout << endl;
}

struct Node
{
    //private:
        Elements_Data Data;
        Node *next;
        Node *prev;
        //friend class CircularSinlgyLinkedList;
};

class CircularSinglyLinkedList{
    private:
        Node* head;
    public:
        CircularSinglyLinkedList();
        ~CircularSinglyLinkedList();

        void deleteList(Node *);

        void addFront(Elements_Data);
        void addBack(Elements_Data);
        void addAscending(Elements_Data); // BY AGE

        void printForward();
        void printReverse();
        void auxReverse(Node *);

        void searchById(string);
        void deleteById(string);

        bool checkForId(string);

};

CircularSinglyLinkedList::CircularSinglyLinkedList(){
    head = NULL;
}

CircularSinglyLinkedList::~CircularSinglyLinkedList(){
    if(head) {
        deleteList(head);
        head = NULL;
        cout << "Lista destruida con exito" << endl;
    }
}

void CircularSinglyLinkedList::deleteList(Node *p){
    if(p!=head) deleteList(p->next);
    delete p;
}

void CircularSinglyLinkedList::addFront(Elements_Data D){
    Node *tmp = new Node;
    tmp->Data = D;
    if(!head){
        head = tmp;
        head->next = head;
    }
    else{
        tmp->next = head;
        Node *s = head;
        while(s->next!=head){
            s = s->next;
        }
        s->next = tmp;
        head = tmp;
    }
}

void CircularSinglyLinkedList::addBack(Elements_Data D){
    Node *tmp = new Node;
    tmp->Data = D;
    if(!head){
        head = tmp;
        head->next = head;
    }
    else{
        tmp->next = head;
        Node *s = head;
        while(s->next!=head){
            s = s->next;
        }
        s->next = tmp;
    }
}

void CircularSinglyLinkedList::addAscending(Elements_Data D){
    Node *tmp = new Node;
    tmp->Data = D;
    if(!head){
        head = tmp;
        head->next = head;
    }
    else{
        if(tmp->Data.age < head->Data.age){
            tmp->next = head;
            Node *s = head;
            while(s->next!=head){
                s = s->next;
            }
            s->next = tmp;
            head = tmp;
        }
        else{
            Node *s = head;
            while(s->next!=head && s->next->Data.age < tmp->Data.age ) s = s->next;
            tmp->next = s->next;
            s->next = tmp;
        }
    }
}


void CircularSinglyLinkedList::printForward(){
    if(head){
        Node *s = head;
        cout << "************Lista de mascotas************" << endl;
        do{
            cout << "owner's name: " << s->Data.owner_name << endl;
            cout << "id: " << s->Data.id << endl;
            cout << "raza de la mascota: " << s->Data.pet_breed<< endl;
            cout << "peso de la mascota: " << s->Data.weight << "kg" << endl;
            cout << "edad de la mascota: " << s->Data.age << endl;
            cout << endl;
            s = s->next;
        }while(s!=head);
    }
}

void CircularSinglyLinkedList::printReverse(){
    if(head) {
        cout << "************Lista de mascotas************" << endl;
        auxReverse(head);
    }
}

void CircularSinglyLinkedList::auxReverse(Node* s){
    if(s->next != head){
        auxReverse(s->next);
    }
    cout << "owner's name: " << s->Data.owner_name << endl;
    cout << "id: " << s->Data.id << endl;
    cout << "raza de la mascota: " << s->Data.pet_breed<< endl;
    cout << "peso de la mascota: " << s->Data.weight << "kg" << endl;
    cout << "edad de la mascota: " << s->Data.age << endl;
    cout << endl;
}

void CircularSinglyLinkedList::searchById(string D){
    if(!head){
        cout << "La Lista esta vacia" << endl;
    }
    else{
        if( D == head->Data.id){
            showData(head->Data);
        }
        else{
            Node *s = head;
            while(s->next!=head && s->Data.id != D ) s = s->next;
            if( s->Data.id == D) showData(s->Data);
            else{
                cout << "id no encontrado" << endl;
            }
        }
    }
}

bool CircularSinglyLinkedList::checkForId(string D){   // lo mismo que searchById pero con bool
    if(!head){
        return false;
    }
    else{
        if( D == head->Data.id){
            return true;
        }
        else{
            Node *s = head;
            while(s->next!=head && s->Data.id != D ) s = s->next;
            if( s->Data.id == D) return true;
            else{
                return false;
            }
        }
    }
}

void CircularSinglyLinkedList::deleteById(string D){
    if(!head){
        cout << "La Lista esta vacia" << endl;
    }
    else{
        if( D == head->Data.id){

            if(head == head->next) 
            {
                head = NULL;
            }
            else 
            {
                Node *aux , *s = head;
                aux = head;
                while(s->next != head ) s = s->next;
                s->next = head->next;
                head = head->next;
                delete aux;
            }
            cout << "Eliminado correctamente" << endl;
        }
        else{
            Node *s = head;
            while(s->next!=head && s->next->Data.id != D ) s = s->next;
            if( s->next->Data.id == D){
                Node *aux;
                aux = s->next;
                s->next = s->next->next;
                delete aux;
                cout << "Eliminado correctamente" << endl;
                
            }
            else{
                cout << "id no encontrado" << endl;
            }
        }
    }
}