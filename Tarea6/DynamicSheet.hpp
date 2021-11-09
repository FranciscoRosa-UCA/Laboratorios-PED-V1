#include <iostream>
//Francisco Alonso Torres Rosa - 00046821

using namespace std;
/*
struct TypeData{
    int Entero;
};
*/
struct Node{
        int nRow, nColumn;
        int DATA;
        Node *nextRow;
        Node *nextColumn;
};

Node giveData(){
    Node dt;
    cout << "Fila: "; cin >> dt.nRow;
    cout << "Columna: "; cin >> dt.nColumn;
    cout << "Numero entero: "; cin >> dt.DATA;
    cin.ignore();
    return dt;
}

class DynamicSheet
{
    private:
        int TRows;
        int TColumns;
        Node *BaseNode;
    public:
        DynamicSheet(int, int);
        //~DynamicSheet();
        void addNode(int, int, int D);
        void deleteNode(int, int);

        void sumRows(int Row);
        void sumColumns(int Column);

        void printAll();
};

DynamicSheet::DynamicSheet(int TRows, int TColumns){
    Node *tmp, *s;
    
    BaseNode = new Node;

    this->TRows = TRows;
    this->TColumns = TColumns;
    BaseNode->nextColumn = BaseNode;
    BaseNode->nextRow = BaseNode;
    BaseNode->nColumn = 0;
    BaseNode->nRow = 0;
    BaseNode->DATA = 0;

    s = BaseNode;
    for (int i = 1; i <= TColumns; i++){  //Creacion de Fila Base
        tmp = new Node;
        s->nextColumn = tmp;
        tmp->DATA = 0;

        tmp->nColumn = i;
        tmp->nRow = 0;
        tmp->nextRow = tmp;

        s = s->nextColumn;
    }
    tmp->nextColumn = BaseNode;

    s = BaseNode;
    for (int i = 1; i <= TRows; i++){  //Creacion de Columna Base
        tmp = new Node;
        s->nextRow = tmp;
        tmp->DATA = 0;

        tmp->nColumn = 0;
        tmp->nRow = i;
        tmp->nextColumn= tmp;

        s = s->nextRow;
    }
    tmp->nextRow = BaseNode;
    
}


void DynamicSheet::printAll(){
    Node *s = BaseNode;
    int sColumn = 0;
    int sRow = 0;
    do{
        do{
            if(sColumn == s->nColumn && sRow == s->nRow){
                cout << s->nRow << "," << s->nColumn << "," << s->DATA << "\t";
                s = s->nextColumn;
            }
            else{
                cout << "\t";
            }
            sColumn++;
        }while(s->nColumn != 0);
        cout << endl;
        s = s->nextRow;

        sColumn = 0;
        sRow++;
    }while(s->nRow != 0);
}

void DynamicSheet::addNode(int nodeRow, int nodeColumn, int D){
    Node *s = BaseNode;
    if(nodeRow >= 1 && nodeRow <= TRows && nodeColumn >= 1 && nodeColumn <= TColumns){
        
        Node *tmp = new Node;
        tmp->DATA = D;
        tmp->nRow = nodeRow;
        tmp->nColumn = nodeColumn;

        Node *pRow = BaseNode;
        Node *pColumn = BaseNode;

        int i;

        for(i = 1; i <= nodeRow; i++)
            pRow = pRow->nextRow;

        while( (pRow->nextColumn->nColumn < nodeColumn) && (pRow->nextColumn->nColumn != 0) )
            pRow = pRow->nextColumn;

        for(i = 1; i <= nodeColumn; i++)
            pColumn = pColumn->nextColumn;
        
        while( (pColumn->nextRow->nRow < nodeRow) && (pColumn->nextRow->nRow != 0) )
            pColumn = pColumn->nextRow;

        if( pColumn->nextRow->nRow != nodeRow  && pRow->nextColumn->nColumn != nodeColumn ){

                tmp->nextColumn = pRow->nextColumn;
                pRow->nextColumn = tmp;

                tmp->nextRow = pColumn->nextRow;
                pColumn->nextRow = tmp;

                cout << "Agregado con exito" << endl;
        }
        else{
            cout << "Esta celda ya existe" << endl;

        }

    }else{
        cout << "Ubicacion no valida, fuera de rango" << endl;
    }
}

void DynamicSheet::sumColumns(int Column){
    if(Column >= 1 && Column <= TColumns){
        Node *s = BaseNode;
        int sum = 0;
        while( s->nColumn != Column) s = s->nextColumn;
            do{
                s = s->nextRow;
                sum += s->DATA;
            }while(s->nRow != 0);
        cout << "La suma de la columna " << Column << " es: " << sum << endl;
    }
    else{
        cout << "Columna fuera de rango." << endl;
    }
}

void DynamicSheet::sumRows(int Row){
    if(Row >= 1 && Row <= TRows ){
        Node *s = BaseNode;
        int sum = 0;
        while( s->nRow != Row) s = s->nextRow;
            do{
                s = s->nextColumn;
                sum += s->DATA;
            }while(s->nColumn != 0);
        cout << "La suma de la fila " << Row << " es: " << sum << endl;
    }
    else{
        cout << "Fila fuera de rango." << endl;
    }
}

void DynamicSheet::deleteNode(int nodeRow, int nodeColumn){
    if(nodeRow >= 1 && nodeRow <= TRows && nodeColumn >= 1 && nodeColumn <= TColumns){
        Node *pRow = BaseNode;
        Node *pColumn = BaseNode;
        Node *pDelete = NULL;

        int i;

        for(i = 1; i <= nodeRow; i++)
            pRow = pRow->nextRow;
        
        while( (pRow->nextColumn->nColumn < nodeColumn) && (pRow->nextColumn->nColumn != 0) )
            pRow = pRow->nextColumn;

        for(i = 1; i <= nodeColumn; i++)
            pColumn = pColumn->nextColumn;
        
        while( (pColumn->nextRow->nRow < nodeRow) && (pColumn->nextRow->nRow != 0) )
            pColumn = pColumn->nextRow;

        if(pColumn->nextRow->nRow == nodeRow  && pRow->nextColumn->nColumn == nodeColumn ){
            pDelete = pRow->nextColumn;
            pRow->nextColumn = pRow->nextColumn->nextColumn;
            pColumn->nextRow = pColumn->nextRow->nextRow;

            delete pDelete;

            cout << "Celda eliminada con exito." << endl;
        }
        else{
            cout << "Esta celda no existe." << endl;
        }
    }
    else{
        cout << "Celda fuera de rango." << endl;
    }
}