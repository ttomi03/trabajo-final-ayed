#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct NodoE;
typedef struct NodoE * NodoPtr;
typedef void * DatoPtr;

NodoPtr crearNodo (DatoPtr dato, NodoPtr siguiente);
void liberarNoDO(NodoPtr nodo);
DatoPtr getDato (NodoPtr nodo);
NodoPtr getSiguiente (NodoPtr nodo);
void setDato (NodoPtr nodo, DatoPtr nuevoDato);
void setSiguiente (NodoPtr nodo, NodoPtr nuevoSiguiente);

#endif // NODO_H_INCLUDED
