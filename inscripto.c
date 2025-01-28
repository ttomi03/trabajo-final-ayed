#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inscripto.h"
#include "lista.h"

struct InscriptoE {
    int id;
    char nombre[50];
    ListaPtr materiasAprobadas;
    float promedio;
};

InscriptoPtr crearInscripto(int id, char nombre[50]) {
    InscriptoPtr inscripto = (InscriptoPtr)malloc(sizeof(struct InscriptoE));
    inscripto->id = id;
    strcpy(inscripto->nombre, nombre);
    inscripto->materiasAprobadas = crearLista();
    return inscripto;
}

void destruirInscripto(InscriptoPtr inscripto) {
    liberarLista(inscripto->materiasAprobadas);
    free(inscripto);
}

void agregarMateriaAprobada(InscriptoPtr inscripto, DatoPtr dato) {
    insertarPrimero(inscripto->materiasAprobadas, dato);
    inscripto->promedio= calcularPromedioInscripto(inscripto);
}

float calcularPromedioInscripto(InscriptoPtr inscripto) {
    NodoPtr actual = getPrimero(inscripto->materiasAprobadas);
    float sumaNotas = 0.0;
    int cantidadMaterias = obtenerTamanio(inscripto->materiasAprobadas);

    while (actual != NULL) {
        MateriaAprobadaPtr materiaAprobada = *(MateriaAprobadaPtr *)getDato(actual);
        sumaNotas += getNota(materiaAprobada);
        actual = getSiguiente(actual);
    }

    return sumaNotas / cantidadMaterias;
}

int cantidadMateriasAprobadas(InscriptoPtr inscripto) {
    return obtenerTamanio(inscripto->materiasAprobadas);
}

void mostrarInscripto(InscriptoPtr inscripto) {
    printf("ID: %d\nNombre: %s\nMaterias Aprobadas: %d\n", inscripto->id, inscripto->nombre, cantidadMateriasAprobadas(inscripto));
    printf ("PROMEDIO: %f\n", inscripto->promedio);

    mostrarListaGenerica(inscripto->materiasAprobadas, &mostrarMateriaAprobadaDatoPtr);
    printf("\n");
}

void mostrarInscriptoDatoPtr(void *p) {
    InscriptoPtr inscripto = *(InscriptoPtr *)p;
    mostrarInscripto(inscripto);
}

int compararInscriptos2(void *p, void *p2)
{
   InscriptoPtr inscripto1 = *(InscriptoPtr *)p;
    InscriptoPtr inscripto2 = *(InscriptoPtr *)p2;

    if (cantidadMateriasAprobadas(inscripto1)!= cantidadMateriasAprobadas(inscripto2)) {
        return cantidadMateriasAprobadas(inscripto1) - cantidadMateriasAprobadas(inscripto2);
    }

    /// SI TIENEN LA MISMA CANTIDAD DE MATERIAS SE COMPARAN LOS PROMEDIOS
    return inscripto1->promedio - inscripto2->promedio;
}
