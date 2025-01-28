#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"
#include "cola.h"|

struct ListaE;
typedef struct ListaE * ListaPtr;


ListaPtr crearLista();
void liberarLista(ListaPtr lista);
void insertarPrimero(ListaPtr lista, DatoPtr dato);
DatoPtr getDato(NodoPtr nodo);
void insertarEnOrden (ListaPtr lista, DatoPtr dato, int (*comparar)(DatoPtr, DatoPtr));
int obtenerTamanio(ListaPtr lista);
void mostrarListaGenerica(ListaPtr lista, void (*mostrar)(void *));
void encolarElementos(ListaPtr lista, ColaPtr cola);

#endif // LISTA_H_INCLUDED
