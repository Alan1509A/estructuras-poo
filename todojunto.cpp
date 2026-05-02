#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;

class Estructura {
public:
    virtual void insertar(int x) = 0;
    virtual void eliminar() = 0;
    virtual void mostrar() = 0;
};

class ColaEstatica : public Estructura {
private:
    int arr[5];
    int frente, fin;

public:
    ColaEstatica(){ frente = 0; fin = 0; }

    void insertar(int x){
        if(fin < 5) arr[fin++] = x;
    }

    void eliminar(){
        if(frente < fin) frente++;
    }

    void mostrar(){
        for(int i = frente; i < fin; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class ListaEstatica : public Estructura {
private:
    int arr[5];
    int n;

public:
    ListaEstatica(){ n = 0; }

    void insertar(int x){
        if(n < 5) arr[n++] = x;
    }

    void eliminar(){
        if(n > 0) n--;
    }

    void mostrar(){
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class Nodo {
public:
    int dato;
    Nodo* sig;

    Nodo(int x){
        dato = x;
        sig = NULL;
    }
};

class PilaDinamica : public Estructura {
private:
    Nodo* tope;

public:
    PilaDinamica(){ tope = NULL; }

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
            cout << aux->dato << " ";
            aux = aux->sig;
        }
        cout << endl;
    }
};

class ColaDinamica : public Estructura {
private:
    Nodo *frente, *fin;

public:
    ColaDinamica(){
        frente = fin = NULL;
    }

    void insertar(int x){
        Nodo* nuevo = new Nodo(x);
        if(!fin) frente = fin = nuevo;
        else{
            fin->sig = nuevo;
            fin = nuevo;
        }
    }

    void eliminar(){
        if(frente){
            Nodo* aux = frente;
            frente = frente->sig;
            delete aux;
        }
    }

    void mostrar(){
        Nodo* aux = frente;
        while(aux){
            cout << aux->dato << " ";
            aux = aux->sig;
        }
        cout << endl;
    }
};

class ListaDinamica : public Estructura {
private:
    Nodo* inicio;

public:
    ListaDinamica(){ inicio = NULL; }

    void insertar(int x){
        Nodo* nuevo = new Nodo(x);
        nuevo->sig = inicio;
        inicio = nuevo;
    }

    void eliminar(){
        if(inicio){
            Nodo* aux = inicio;
            inicio = inicio->sig;
            delete aux;
        }
    }

    void mostrar(){
        Nodo* aux = inicio;
        while(aux){
            cout << aux->dato << " ";
            aux = aux->sig;
        }
        cout << endl;
    }
};

int main(){
    int opcion, valor;

    do{
        cout << "\n--- MENU ---\n";
        cout << "1. Cola Estatica\n";
        cout << "2. Lista Estatica\n";
        cout << "3. Pila Dinamica\n";
        cout << "4. Cola Dinamica\n";
        cout << "5. Lista Dinamica\n";
        cout << "6. Pila STL\n";
        cout << "7. Cola STL\n";
        cout << "8. Lista STL\n";
        cout << "0. Salir\n";
        cin >> opcion;

        Estructura* est = NULL;

        switch(opcion){
            case 1: est = new ColaEstatica(); break;
            case 2: est = new ListaEstatica(); break;
            case 3: est = new PilaDinamica(); break;
            case 4: est = new ColaDinamica(); break;
            case 5: est = new ListaDinamica(); break;
        }

        if(est != NULL){
            int op2;
            do{
                cout << "\n1.Insertar 2.Eliminar 3.Mostrar 0.Salir\n";
                cin >> op2;

                switch(op2){
                    case 1:
                        cout << "Valor: ";
                        cin >> valor;
                        est->insertar(valor);
                        break;
                    case 2:
                        est->eliminar();
                        break;
                    case 3:
                        est->mostrar();
                        break;
                }
            }while(op2 != 0);

            delete est;
        }

        // STL
        if(opcion == 6){
            stack<int> p;
            p.push(10); p.push(20); p.pop();
            cout << "Pila STL: " << p.top() << endl;
        }

        if(opcion == 7){
            queue<int> c;
            c.push(1); c.push(2); c.pop();
            cout << "Cola STL: " << c.front() << endl;
        }

        if(opcion == 8){
            list<int> l;
            l.push_back(1); l.push_back(2);
            for(list<int>::iterator it=l.begin(); it!=l.end(); it++)
                cout << *it << " ";
            cout << endl;
        }

    }while(opcion != 0);

    return 0;
}
