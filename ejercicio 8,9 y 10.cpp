#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;

int main(){
    int op,val;

    do{
        cout<<"\n1.Pila 2.Cola 3.Lista 0.Salir\n";
        cin>>op;

        if(op==1){
            stack<int> p;
            p.push(10); p.push(20); p.pop();
            cout<<"Top: "<<p.top()<<endl;
        }

        if(op==2){
            queue<int> c;
            c.push(1); c.push(2); c.pop();
            cout<<"Front: "<<c.front()<<endl;
        }

        if(op==3){
            list<int> l;
            l.push_back(1); l.push_back(2);

            for(list<int>::iterator it=l.begin(); it!=l.end(); it++)
                cout<<*it<<" ";
            cout<<endl;
        }

    }while(op!=0);
}
