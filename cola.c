#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "lista.h"

struct ColaE
{
    NodoPtr primero;
    NodoPtr ultimo;
};

ColaPtr crearCola ()
{
    ColaPtr cola= (ColaPtr)malloc(sizeof(struct ColaE));
    cola->primero=NULL;
    cola->ultimo=NULL;
    return cola;
};
void encolar(ColaPtr cola, DatoPtr dato)
{
    NodoPtr nuevo = crearNodo(dato, NULL);

    if (cola->primero != NULL)
    {
        setSiguiente(cola->ultimo, nuevo);
    }
    else
    {
        cola->primero = nuevo;
    }

    cola->ultimo = nuevo; // Actualizar cola->ultimo
};
DatoPtr desencolar (ColaPtr cola)
{
    if (cola->primero == NULL)
    {
        return NULL;
    }

    NodoPtr eliminar= cola->primero;
    DatoPtr dato= getDato(eliminar);
    cola->primero= getSiguiente(eliminar);

    if (cola->primero == NULL)
    {
        cola->ultimo= NULL;
    }

    liberarNodo(eliminar);
    return dato;
};



