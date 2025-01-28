#ifndef INSCRIPTO_H_INCLUDED
#define INSCRIPTO_H_INCLUDED

#include "materia_aprobada.h"
#include "nodo.h"

typedef struct InscriptoE *InscriptoPtr;
InscriptoPtr crearInscripto(int id, char nombre[50]) ;
void destruirInscripto(InscriptoPtr inscripto);
void agregarMateriaAprobada(InscriptoPtr inscripto, DatoPtr dato);
float calcularPromedioInscripto(InscriptoPtr inscripto);
int cantidadMateriasAprobadas(InscriptoPtr inscripto);
void mostrarInscripto(InscriptoPtr inscripto);
void mostrarInscriptoDatoPtr(void *p);
int compararInscriptos2(void *p, void *p2);

#endif // INSCRIPTO_H_INCLUDED
