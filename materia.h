#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include "inscripto.h"
#include "lista.h"
struct MateriaE;
typedef struct MateriaE *MateriaPtr;
MateriaPtr crearMateria(int codigo, char nombre[], int cupo);
void destruirMateria(MateriaPtr materia);
void agregarInscripto(MateriaPtr materia, DatoPtr inscripto);
void mostrarMateria(MateriaPtr materia);
ListaPtr getLista(MateriaPtr materia);
ColaPtr getcola (MateriaPtr materia);
#endif // MATERIA_H_INCLUDED
