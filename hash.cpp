#include <iostream>
#include "hash.h"

using namespace std;

Hash::Hash(int n) {
    N = n;
    thash = new int[N];
    for (int i = 0; i < N; i++) {
        thash[i] = -1; // Iniciamos entradas como -1 (indicando vacío)
    }
    numPrimo = obtenPrimo(N);
}

int Hash::obtenPrimo(int t) {
    int i;
    bool esPrimo = false;
    while (!esPrimo && t > 2) {
        i = 2;
        while (i < (t / 2 + 1) && t % i != 0) {
            i++;
        }
        if (i >= (t / 2 + 1)) {
            esPrimo = true;
        }
        else {
            t--;
        }
    }
    return t;
}

int Hash::fhash(int clave) {
    return clave % N; 
}

int Hash::rehash(int clave, int colision, int t) {
    int numP;
    int hPrima;
    int pos = fhash(clave);

    while (thash[pos] != -1) {
        numP = obtenPrimo(t);
        hPrima = numP - (clave % numP);
        pos = (fhash(clave) + colision * hPrima) % N;
        colision++;
    }
    return pos;
}

void Hash::insertar(int clave) {
    int colision = 0;
    int pos = fhash(clave);

    if (thash[pos] == -1) {
        thash[pos] = clave; 
    }
    else {
        pos = rehash(clave, colision, N - 1); 
        thash[pos] = clave;
    }
}

bool Hash::buscar(int clave) {
    int colision = 0;
    int pos = fhash(clave);
   
    //un bucle donde nos indique tabla no es=-1 (que esta vacía)
    while (thash[pos] != -1) {
        if (thash[pos] == clave) {
            return true; //la clave se hallo
        } //implemnto colision por sino se halla clave
        colision++; 
        pos = rehash(clave, colision, N - 1); 
    }

    return false; // Clave no hallada
}

void Hash::mostrarTabla() {
    for (int i = 0; i < N; i++) {
        if (thash[i] != -1) {
            cout << "Posición " << i << ": " << thash[i] << endl;
        }
    }
}

int main() {
    Hash h(103);

    h.insertar(223345);
    h.insertar(123456);
    h.insertar(555555);

    if (h.buscar(223345)) {
        cout << "Clave 223345 encontrada." << endl;
    }
    else {
        cout << "Clave 223345 No encontrada." << endl;
    }

    if (h.buscar(999999)) {
        cout << "Clave 999999 encontrada." << endl;
    }
    else {
        cout << "Clave 999999 No encontrada." << endl;
    }

    h.mostrarTabla();

    return 0;
}

