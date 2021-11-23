#include <iostream>

using namespace std;


struct Node{
    int DATA;
    Node *right;
    Node *left;
    Node *father;
};

class BST{
    private:
        Node *pBST;

        Node* createNode(int, Node*);
        void deleteNode(Node *&);
        Node* minimunNode(Node *&);
        void replaceNode(Node *, Node*);
        void auxDestroyNode(Node *);

        void search_RecDeleteNode(Node *&, int);

        void printIn(Node *&);
        void printpre(Node *&);
        void printpost(Node *&);


    public:       

        BST();

        Node*& getpBST();
        

        void addNode(Node*&, int, Node* );
        void search_DeleteNode(Node *&, int);
        void search_DeleteNode_2(int);

        void printInorder();
        void printPreorder();
        void printPostorder();

        void printFullTree(Node *&, int);
};

BST::BST(){
    pBST = NULL;
}

Node*& BST::getpBST(){
    return pBST;
}

Node* BST::createNode(int key, Node *father){
    Node* tmp = new Node;
    tmp->DATA = key;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->father = father;
}

void BST::addNode(Node *&p, int key, Node *father){
    if(!p){
        Node* tmp = createNode(key, father);
        p = tmp;
    }
    else{
        int RootValue = p->DATA;

        if( key < RootValue){
            addNode(p->left, key, p);
        }
        else if( key > p->DATA){
            addNode(p->right, key, p);
        }
        else{
            cout << "La llave ya existe" << endl;
        }
    }
}

void BST::printInorder(void)
{
    printIn(getpBST());
}

void BST::printIn(Node *&p)
{
    if (p)
    {
        printIn(p->left);
        cout << p->DATA << "  ";
        printIn(p->right);
    }
}
void BST::printPreorder(void)
{
    printpre(getpBST());
}

void BST::printpre(Node *&p)
{
    if (p)
    {
        cout << p->DATA << "  ";
        printpre(p->left);
        printpre(p->right);
    }
}

void BST::printPostorder(void)
{
    printpost(getpBST());
}


void BST::printpost(Node *&p)
{
    if (p)
    {
        printpost(p->left);
        printpost(p->right);
        cout << p->DATA << "  ";
    }
}

void BST::search_DeleteNode_2(int Data)  // Version Ing Guillermo.
{
    search_RecDeleteNode(getpBST(), Data);
}

void BST::search_RecDeleteNode(Node *& r, int Data){
    Node *p;
    if(!r)
        cout << "El dato no esta en el arbol" << endl;
    else
        if(Data < r->DATA)
            search_RecDeleteNode(r->left, Data);
        else
            if(Data > r->DATA)
                search_RecDeleteNode(r->right, Data);
            else{
                if(!r->left && !r->right){
                    p = r;
                    r = NULL;
                }
                else
                    if(!r->left && r->right){
                        p = r;
                        r = r->right;
                    }
                    else
                        if(r->left && !r->right){
                            p = r;
                            r = r->left;
                        }
                        else
                            if(r->left && r->right){
                                p = r->left;
                                if(!p->right){
                                    r->DATA = p->DATA;
                                    r->left = p->left;
                                }
                                else{
                                    Node *q;
                                    while(p->right){
                                        q = p;
                                        p = p->right;
                                    }
                                    r->DATA = p->DATA;
                                    q->right = p->left;
                                }
                            }

                delete p;

            }
    
}

void BST::search_DeleteNode(Node *&p, int key){  //Mi propia version, incluyendo el puntero father.
    if( getpBST() == p){
        if(p == NULL){
            cout << "El arbol esta vacio" << endl;
        }
        else if(key < p->DATA){
            search_DeleteNode(p->left, key);
        }
        else if(key > p->DATA){
            search_DeleteNode(p->right, key);
        }
        else{
            deleteNode(p);
            cout << "Llave eliminada con exito" << endl;
        }
    }
    else{
        if(p == NULL){
            cout << "La llave no existe" << endl;
        }
        else if(key < p->DATA){
            search_DeleteNode(p->left, key);
        }
        else if(key > p->DATA){
            search_DeleteNode(p->right, key);
        }
        else{
            deleteNode(p);
            cout << "Llave eliminada con exito" << endl;
        }
    }
} 

void BST::deleteNode(Node *&key){

    if(key->left && key->right){//Si hay sub nodo left y right
        Node *minimun = minimunNode(key->right);
        key->DATA = minimun->DATA;
        deleteNode(minimun);
    }
    else if(key->left){//Si hay sub nodo left
        replaceNode(key,key->left);
        //auxDestroyNode(key);
    }
    else if(key->right){//Si hay sub nodo right
        replaceNode(key,key->right);
        //auxDestroyNode(key);
    }
    else{//Si no hay sub nodo
        replaceNode(key,NULL);
        //auxDestroyNode(key);
    }
    
}

void BST::replaceNode(Node *key , Node *newKey){
    if(key->father){
        if( key->father->left != NULL ){
            if(key->DATA == key->father->left->DATA ){
                key->father->left = newKey;
            }
        }
        if(key->father->right != NULL){
            if(key->DATA == key->father->right->DATA){
                key->father->right = newKey;
            }
        }
    }
    if(newKey){
        newKey->father=key->father;
    }
    auxDestroyNode(key);
}

void BST::auxDestroyNode(Node *p){

    p->left=NULL;
    p->right=NULL;
    p->father=NULL;
    if(p != getpBST()){
        delete p;
    }

}

Node *BST::minimunNode(Node *&p){
    if(p == NULL)
    {
        return NULL;
    }
    else if(p->left)
    {
        return minimunNode(p->left);
    }
    else{
        return p;
    }
}

void BST::printFullTree(Node *&p, int count){
    if(!p){
        return;
    }
    else{
        printFullTree(p->right, count+1);
        for(int i = 0; i < count; i++){
            cout << "       ";
        }
        cout << p->DATA << endl;
        printFullTree(p->left, count+1);
    }
}