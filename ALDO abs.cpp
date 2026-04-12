#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;


#define MAX 5
int cola[MAX];
int frente = 0, fin = 0;

void enqueueE(int x){
    if(fin < MAX) cola[fin++] = x;
}

void dequeueE(){
    if(frente < fin) frente++;
}

void mostrarColaE(){
    for(int i = frente; i < fin; i++)
        cout << cola[i] << " ";
}

// ================= LISTA ESTATICA =================
int listaE[5];
int n = 0;

void insertarE(int x){
    if(n < 5) listaE[n++] = x;
}

void mostrarListaE(){
    for(int i = 0; i < n; i++)
        cout << listaE[i] << " ";
}

// ================= PILA DINAMICA =================
struct Nodo{
    int dato;
    Nodo *sig;
};

Nodo *tope = NULL;

void pushD(int x){
    Nodo *nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->sig = tope;
    tope = nuevo;
}

void popD(){
    if(tope){
        Nodo *aux = tope;
        tope = tope->sig;
        delete aux;
    }
}

void mostrarPilaD(){
    Nodo *aux = tope;
    while(aux){
        cout << aux->dato << " ";
        aux = aux->sig;
    }
}

// ================= COLA DINAMICA =================
Nodo *frenteD = NULL;
Nodo *finD = NULL;

void enqueueD(int x){
    Nodo *nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->sig = NULL;

    if(!finD) frenteD = finD = nuevo;
    else{
        finD->sig = nuevo;
        finD = nuevo;
    }
}

void dequeueD(){
    if(frenteD){
        Nodo *aux = frenteD;
        frenteD = frenteD->sig;
        delete aux;
    }
}

void mostrarColaD(){
    Nodo *aux = frenteD;
    while(aux){
        cout << aux->dato << " ";
        aux = aux->sig;
    }
}

// ================= LISTA DINAMICA =================
Nodo *inicio = NULL;

void insertarD(int x){
    Nodo *nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->sig = inicio;
    inicio = nuevo;
}

void mostrarListaD(){
    Nodo *aux = inicio;
    while(aux){
        cout << aux->dato << " ";
        aux = aux->sig;
    }
}

// ================= MAIN =================
int main(){
    int op;

    do{
        cout << "\n--- MENU ---\n";
        cout << "4. Cola Estatica\n";
        cout << "5. Lista Estatica\n";
        cout << "6. Pila Dinamica\n";
        cout << "7. Cola Dinamica\n";
        cout << "8. Pila STL\n";
        cout << "9. Cola STL\n";
        cout << "10. Lista STL\n";
        cout << "0. Salir\n";
        cin >> op;

        switch(op){

        case 4:
            enqueueE(1); enqueueE(2); enqueueE(3);
            dequeueE();
            cout << "Cola estatica: ";
            mostrarColaE();
            break;

        case 5:
            insertarE(10); insertarE(20); insertarE(30);
            cout << "Lista estatica: ";
            mostrarListaE();
            break;

        case 6:
            pushD(5); pushD(10); pushD(15);
            popD();
            cout << "Pila dinamica: ";
            mostrarPilaD();
            break;

        case 7:
            enqueueD(1); enqueueD(2); enqueueD(3);
            dequeueD();
            cout << "Cola dinamica: ";
            mostrarColaD();
            break;

        case 8:{
            stack<int> pila;
            pila.push(10);
            pila.push(20);
            pila.pop();
            cout << "Pila STL: " << pila.top();
            break;
        }

        case 9:{
            queue<int> cola;
            cola.push(1);
            cola.push(2);
            cola.pop();
            cout << "Cola STL: " << cola.front();
            break;
        }

        case 10:{
            list<int> lista;
            lista.push_back(1);
            lista.push_back(2);
            lista.push_back(3);

            cout << "Lista STL: ";
            list<int>::iterator it;
            for(it = lista.begin(); it != lista.end(); it++){
                cout << *it << " ";
            }
            break;
        }

        }

    }while(op != 0);

    return 0;
}

