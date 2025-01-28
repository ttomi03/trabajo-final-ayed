#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "nodo.h"
#include "inscripto.h"
struct ColaE;
typedef struct ColaE * ColaPtr;

ColaPtr crearCola ();
void encolar (ColaPtr cola, DatoPtr dato);
DatoPtr desencolar (ColaPtr cola);


#endif // COLA_H_INCLUDED
