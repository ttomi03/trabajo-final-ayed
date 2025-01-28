#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

struct NodoE
{
    DatoPtr dato;
    struct NodoE*siguiente;
};
NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente)
{
    NodoPtr nodo= (NodoPtr)malloc(sizeof(struct NodoE));
    nodo->dato=dato;
    nodo->siguiente=siguiente;

    return nodo;
};
void liberarNodo(NodoPtr nodo)
{
    free(nodo);
};
DatoPtr getDato (NodoPtr nodo)
{
    return nodo->dato;
};
NodoPtr getSiguiente (NodoPtr nodo)
{
    return nodo->siguiente;
};
void setDato(NodoPtr nodo, DatoPtr nuevodato)
{
    nodo->dato=nuevodato;
};
void setSiguiente (NodoPtr nodo, NodoPtr nuevoSiguiente)
{
    nodo->siguiente=nuevoSiguiente;
};

