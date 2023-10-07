#pragma once

class Hash {
private:
    int* thash;   // Arreglo de la tabla hash
    int N;        // Tamaño de la tabla hash
    int numPrimo; // Número primo para la tabla hash

public:
    Hash(int n);
    int obtenPrimo(int t);
    int fhash(int clave);
    int rehash(int clave, int colision, int t);
    void insertar(int clave);
    bool buscar(int clave);
    void mostrarTabla();
};



