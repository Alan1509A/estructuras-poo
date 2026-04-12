#ifndef PILA_H
#define PILA_H

#include <iostream>
using namespace std;

class Pila {
private:
    int arr[100];
    int top;

public:
    Pila() { top = -1; }

    void push(int x) {
        if (top < 99)
            arr[++top] = x;
    }

    void pop() {
        if (top >= 0)
            top--;
    }

    void mostrar() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << endl;
    }
};

#endif
