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

class PilaDinamica : public Estructura {
private:
    Nodo* tope;

public:
    PilaDinamica(){ tope=NULL; }

    void insertar(int x){
        Nodo* nuevo = new Nodo(x);
        nuevo->sig = tope;
        tope = nuevo;
    }

    void eliminar(){
        if(tope){
            Nodo* aux = tope;
            tope = tope->sig;
            delete aux;
        }
    }

    void mostrar(){
        Nodo* aux = tope;
        while(aux){
            cout<<aux->dato<<" ";
            aux=aux->sig;
        }
        cout<<endl;
    }
};

int main(){
    Estructura* pila = new PilaDinamica();
    int op,val;

    do{
        cout<<"\n1.Push 2.Pop 3.Mostrar 0.Salir\n";
        cin>>op;

        switch(op){
            case 1: cin>>val; pila->insertar(val); break;
            case 2: pila->eliminar(); break;
            case 3: pila->mostrar(); break;
        }
    }while(op!=0);

    delete pila;
}
