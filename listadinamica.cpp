#include <iostream>
using namespace std;

class Estructura {
public:
    virtual void insertar(int x)=0;
    virtual void eliminar()=0;
    virtual void mostrar()=0;
};

class Nodo{
public:
    int dato;
    Nodo* sig;
    Nodo(int x){ dato=x; sig=NULL; }
};

class ListaDinamica : public Estructura {
private:
    Nodo* inicio;

public:
    ListaDinamica(){ inicio=NULL; }

    void insertar(int x){
        Nodo* nuevo=new Nodo(x);
        nuevo->sig=inicio;
        inicio=nuevo;
    }

    void eliminar(){
        if(inicio){
            Nodo* aux=inicio;
            inicio=inicio->sig;
            delete aux;
        }
    }

    void mostrar(){
        Nodo* aux=inicio;
        while(aux){
            cout<<aux->dato<<" ";
            aux=aux->sig;
        }
        cout<<endl;
    }
};

int main(){
    Estructura* lista = new ListaDinamica();
    int op,val;

    do{
        cout<<"\n1.Insertar 2.Eliminar 3.Mostrar 0.Salir\n";
        cin>>op;

        switch(op){
            case 1: cin>>val; lista->insertar(val); break;
            case 2: lista->eliminar(); break;
            case 3: lista->mostrar(); break;
        }
    }while(op!=0);

    delete lista;
}
