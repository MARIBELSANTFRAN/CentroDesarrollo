#include <iostream>
#define HASHMAX 10

using namespace std;

typedef struct nodoL
{
    int info;
    nodoL* sig;
    nodoL* ant;
} nodo;

typedef nodo* lista;

// DEFINICIÓN DE LAS FUNCIONES
// ************* HASH **********

typedef lista Hash[HASHMAX];
int HashClave(int n);
void HashInsertar(Hash& h, int e);
void HashMostrar(Hash h);

// ********  LISTA   *******
void enlistar(lista& L, int n);
int mostrar(lista L);
void borrar(lista& L, int n);

int HashClave(int n)
{
    return n % HASHMAX;
}

void HashInsertar(Hash& h, int e)
{
    enlistar(h[HashClave(e)], e);
}

void enlistar(lista& L, int n)
{
    lista aux = new nodoL;
    if (L == NULL)
    {
        aux->info = n;
        aux->sig = L;
        L = aux;
    }
    else
    {
        aux->info = n;
        aux->sig = L;
        L = aux;
    }
}

int mostrar(lista L)
{
    int i = 0;
    while (L != NULL)
    {
        i = 1;
        cout << "[" << L->info << "]->";
        L = L->sig;
    }
    return i;
}

void HashMostrar(Hash h)
{
    int i, n;
    for (n = 0; n < HASHMAX; n++)
    {
        cout << "Hash [" << n << "]: ";
        i = mostrar(h[n]);
        if (i == 0) cout << "Lista vacia " << endl << endl;
        else cout << "#" << endl << endl;
    }
}

int main()
{
    int op = -1;
    lista milista = NULL;
    Hash h;

    while (op != 0)
    {
        system("cls");
        cout << "\t\tHash Example" << endl << endl;
        cout << "\tSelect an option" << endl << endl;
        cout << "\t-1. Add an element to the list" << endl;
        cout << "\t-2. Show the list" << endl;
        cout << "\t-3. Delete an element" << endl;
        cout << "\t-0. Exit" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int e, n;
            system("cls");
            cout << "Enter the hash key for the element:" << endl;
            cin >> n;
            cout << "Enter the number to add to the list, 0 to finish:" << endl;
            do {
                cin >> e;
                HashInsertar(h, e);
                cout << e << " has been successfully added to the list" << endl;
            } while (e != 0);
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Numbers loaded in the list:" << endl << endl;
            int i = mostrar(milista);
            if (i == 0)
                cout << "The list is empty" << endl << endl;
            else
                cout << "#" << endl << endl;
            system("pause");
            break;
        }
        case 3:
        {
            int n;
            system("cls");
            cout << "Enter the number to delete from the list:" << endl;
            cin >> n;
            system("cls");
            borrar(milista, n);
            cout << "Element deleted from the list. Press any key to return" << endl;
            system("pause");
            break;
        }
        }
    }

    system("pause");
    return 0;
}
