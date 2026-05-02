#include <iostream>
using namespace std;

class Estructura {
public:
    virtual void insertar(int x)=0;
    virtual void eliminar()=0;
    virtual void mostrar()=0;
};

class ColaEstatica : public Estructura {
private:
    int arr[5];
    int frente, fin;

public:
    ColaEstatica(){ frente=0; fin=0; }

    void insertar(int x){
        if(fin<5) arr[fin++]=x;
    }

    void eliminar(){
        if(frente<fin) frente++;
    }

    void mostrar(){
        for(int i=frente;i<fin;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    Estructura* cola = new ColaEstatica();
    int op, val;

    do{
        cout<<"\n1.Insertar 2.Eliminar 3.Mostrar 0.Salir\n";
        cin>>op;

        switch(op){
            case 1: cin>>val; cola->insertar(val); break;
            case 2: cola->eliminar(); break;
            case 3: cola->mostrar(); break;
        }
    }while(op!=0);

    delete cola;
}
