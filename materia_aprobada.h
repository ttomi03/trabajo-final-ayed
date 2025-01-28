#ifndef MATERIA_APROBADA_H_INCLUDED
#define MATERIA_APROBADA_H_INCLUDED

struct MateriaAprobadaE;
typedef struct MateriaAprobadaE *MateriaAprobadaPtr;
MateriaAprobadaPtr crearMateriaAprobada(int codigo, char nombre[50], float nota);
void destruirMateriaAprobada(MateriaAprobadaPtr materia);
void mostrarMateriaAprobada(MateriaAprobadaPtr materia);
void mostrarMateriaAprobadaDatoPtr(void *p);
float getNota (MateriaAprobadaPtr materia);

#endif // MATERIA_APROBADA_H_INCLUDED
