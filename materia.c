#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.h"
#include "inscripto.h"
#include "nodo.h"
#include "lista.h"
#include "cola.h"
struct MateriaE {
    int codigo;
    char nombre[50];
    int cupo;
    ListaPtr inscriptos;
    ListaPtr pendientes;
    ColaPtr colaPendiente;
};
MateriaPtr crearMateria(int codigo, char nombre[], int cupo) {
    MateriaPtr materia = (MateriaPtr)malloc(sizeof(struct MateriaE));
    materia->codigo = codigo;
    strcpy(materia->nombre, nombre);
    materia->cupo = cupo;
    materia->inscriptos = crearLista();
    materia->pendientes = crearLista();
    materia->colaPendiente=crearCola();
    return materia;
}
void destruirMateria(MateriaPtr materia) {
    liberarLista(materia->inscriptos);
    liberarLista(materia->pendientes);
    free(materia);
}
void agregarInscripto(MateriaPtr materia, DatoPtr inscripto) {

    if(obtenerTamanio(materia->inscriptos) <= materia->cupo)
    {
        insertarPrimero(materia->inscriptos, inscripto);
    }else
    {
        insertarEnOrden(materia->pendientes, inscripto, &compararInscriptos2);
    }


}
void mostrarMateria(MateriaPtr materia) {
    printf("MATERIA: %s\n", materia->nombre);
    mostrarListaGenerica(materia->inscriptos, &mostrarInscriptoDatoPtr);
}
ListaPtr getLista(MateriaPtr materia)
{
    return materia->pendientes;
}

ColaPtr getcola (MateriaPtr materia)
{
    return materia->colaPendiente;
}

