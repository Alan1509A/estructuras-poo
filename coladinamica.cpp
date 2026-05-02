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

class ColaDinamica : public Estructura {
private:
    Nodo *frente,*fin;

public:
    ColaDinamica(){ frente=fin=NULL; }

    void insertar(int x){
        Nodo* nuevo=new Nodo(x);
        if(!fin) frente=fin=nuevo;
        else{
            fin->sig=nuevo;
            fin=nuevo;
        }
    }

    void eliminar(){
        if(frente){
            Nodo* aux=frente;
            frente=frente->sig;
            delete aux;
        }
    }

    void mostrar(){
        Nodo* aux=frente;
        while(aux){
            cout<<aux->dato<<" ";
            aux=aux->sig;
        }
        cout<<endl;
    }
};

int main(){
    Estructura* cola = new ColaDinamica();
    int op,val;

    do{
        cout<<"\n1.Enqueue 2.Dequeue 3.Mostrar 0.Salir\n";
        cin>>op;

        switch(op){
            case 1: cin>>val; cola->insertar(val); break;
            case 2: cola->eliminar(); break;
            case 3: cola->mostrar(); break;
        }
    }while(op!=0);

    delete cola;
}
