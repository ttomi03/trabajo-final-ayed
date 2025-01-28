#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "cola.h"
#include "nodo.h"
struct ListaE {
    NodoPtr primero;
};

ListaPtr crearLista() {
    ListaPtr lista = (ListaPtr)malloc(sizeof(struct ListaE));
    lista->primero = NULL;
    return lista;
}

void liberarLista(ListaPtr lista) {
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        NodoPtr temp = actual;
        actual = getSiguiente(actual);
        free(temp);
    }
    free(lista);
}

void insertarPrimero(ListaPtr lista, DatoPtr dato) {
    NodoPtr nuevo= crearNodo(dato, lista->primero);
    lista->primero=nuevo;
}
NodoPtr getPrimero(ListaPtr lista) {
    return lista->primero;
}

int obtenerTamanio(ListaPtr lista) {
    NodoPtr actual=lista->primero;
    int cont= 0;

    while (actual !=NULL)
    {
        cont=cont +1;
        actual=getSiguiente(actual);
    }
    return cont;
}

void insertarEnOrden (ListaPtr lista, DatoPtr dato, int (*comparar)(DatoPtr, DatoPtr))
{
    NodoPtr nuevo = crearNodo(dato, NULL);

    if (lista->primero == NULL || comparar(dato, getDato(lista->primero)) > 0) {
    setSiguiente(nuevo, lista->primero);
    lista->primero = nuevo;
    return;
    }

    NodoPtr actual = lista->primero;
    NodoPtr siguiente = getSiguiente(actual);

    while (siguiente != NULL && comparar(getDato(siguiente), dato) > 0) {
    actual = siguiente;
    siguiente = getSiguiente(actual);
    }

    setSiguiente(nuevo, siguiente);
    setSiguiente(actual, nuevo);
};

void mostrarListaGenerica(ListaPtr lista, void (*mostrar)(void *)) {
    NodoPtr actual = getPrimero(lista);
    while (actual != NULL) {
        mostrar(getDato(actual));
        actual = getSiguiente(actual);
    }
}

void encolarElementos(ListaPtr lista, ColaPtr cola) {
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        encolar(cola, getDato(actual));
        actual = getSiguiente(actual);
    }
}
