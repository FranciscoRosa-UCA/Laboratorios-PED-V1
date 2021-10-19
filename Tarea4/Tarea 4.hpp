#include <iostream>
using namespace std;

struct Elements_Data{
    string id;
    string name;
    string profile;
};

class Node 
{
    private:
        Elements_Data Data;
        Node *previous;
        Node *next;

        friend class LinkedList;
};

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        Elements_Data getFront() const;
        Elements_Data getBack() const;
        void addFront(Elements_Data);
        void addBack(Elements_Data);

        void removeFront();
        void removeBack();
        void printReverse();
        void printForward();
    
    private:
        Node *header;
        Node *trailer;
};

LinkedList::LinkedList(){
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->previous = header;
    header->previous = NULL;
    trailer->next = NULL;
}

LinkedList::~LinkedList(){
    while(header->next!=trailer){
        removeFront();
    }
    delete header;
    delete trailer;
}

Elements_Data LinkedList::getFront() const{
    return header->next->Data;
}

Elements_Data LinkedList::getBack() const{
    return trailer->previous->Data;
}

void LinkedList::addFront(Elements_Data dt){
    Node *nd = new Node;
    nd->Data = dt;
    nd->previous = header;
    nd->next = header->next; 

    header->next->previous = nd;
    header->next = nd;
}

void LinkedList::addBack(Elements_Data dt){
    Node *nd = new Node;
    nd->Data = dt;
    nd->previous = trailer->previous;
    nd->next=trailer;

    trailer->previous->next = nd;
    trailer->previous = nd;
}

void LinkedList::removeFront(){
    Node *nd=header->next->next;
    delete header->next;

    header->next=nd;
    nd->previous=header;
}

void LinkedList::removeBack(){
    Node *nd = trailer->previous->previous;

    delete trailer->previous;

    trailer->previous=nd;
    nd->next=trailer;
}

void LinkedList::printReverse(){
    Node *nd=trailer->previous;
    while (nd!=header)
    {
        cout << "Nombre: " << nd->Data.name << endl;
        cout << "id: "<< nd->Data.id << endl;
        cout << "Perfil: " << nd->Data.profile << endl;
        cout << endl;
        nd=nd->previous;
    }    

}

void LinkedList::printForward(){
    Node *nd=header->next;
    while (nd!=trailer)
    {
        cout << "Nombre: " << nd->Data.name << endl;
        cout << "id: "<< nd->Data.id << endl;
        cout << "Perfil: " << nd->Data.profile << endl;
        cout << endl;
        nd=nd->next;
    }    
}