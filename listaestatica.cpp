#include <iostream>
using namespace std;

class Estructura {
public:
    virtual void insertar(int x)=0;
    virtual void eliminar()=0;
    virtual void mostrar()=0;
};

class ListaEstatica : public Estructura {
private:
    int arr[5];
    int n;

public:
    ListaEstatica(){ n=0; }

    void insertar(int x){
        if(n<5) arr[n++]=x;
    }

    void eliminar(){
        if(n>0) n--;
    }

    void mostrar(){
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    Estructura* lista = new ListaEstatica();
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
