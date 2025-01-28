#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia_aprobada.h"

struct MateriaAprobadaE {
    int codigo;
    char nombre[50];
    float nota;
};

MateriaAprobadaPtr crearMateriaAprobada(int codigo, char nombre[50], float nota) {
    MateriaAprobadaPtr materia = (MateriaAprobadaPtr)malloc(sizeof(struct MateriaAprobadaE));
    materia->codigo = codigo;
    strcpy(materia->nombre, nombre);
    materia->nota = nota;
    return materia;
}

void destruirMateriaAprobada(MateriaAprobadaPtr materia) {
    free(materia);
}

void mostrarMateriaAprobada(MateriaAprobadaPtr materia) {
    printf("Materia: %s (Codigo: %d) - Nota: %.2f\n", materia->nombre, materia->codigo, materia->nota);
}
float getNota (MateriaAprobadaPtr materia)
{
    return materia->nota;
}
void mostrarMateriaAprobadaDatoPtr(void *p) {
    MateriaAprobadaPtr materia = *(MateriaAprobadaPtr *)p;
    mostrarMateriaAprobada(materia);
}
