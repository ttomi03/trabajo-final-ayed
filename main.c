#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "cola.h"
#include "materia.h"
#include "inscripto.h"
#include "materia_aprobada.h"


int main()
{
    ///MATERIAS DISPONIBLES
    MateriaPtr materia1 = crearMateria(101, "Matematica", 2);
    MateriaPtr materia2 = crearMateria(102, "Programacion", 3);
    ///INSCRIPTOS
    InscriptoPtr inscripto1 = crearInscripto(101, "Juan Perez");
    InscriptoPtr inscripto2 = crearInscripto(102, "Maria Rodriguez");
    InscriptoPtr inscripto3 = crearInscripto(103, "Luis Fernandez");
    InscriptoPtr inscripto4 = crearInscripto(104, "Ana Martinez");
    InscriptoPtr inscripto5 = crearInscripto(105, "Carlos Gonzalez");
    InscriptoPtr inscripto6 = crearInscripto(106, "Sofia Garcia");
    InscriptoPtr inscripto7 = crearInscripto(107, "Pablo Lopez");
    InscriptoPtr inscripto8 = crearInscripto(108, "Laura Sanchez");
    InscriptoPtr inscripto9 = crearInscripto(109, "Diego Perez");
    InscriptoPtr inscripto10 = crearInscripto(110, "Carolina Martinez");
    ///MATERIAS APROBADAS
    MateriaAprobadaPtr matAprobada1 = crearMateriaAprobada(201, "Quimica", 8.5);
    MateriaAprobadaPtr matAprobada2 = crearMateriaAprobada(202, "Fisica", 7.0);
    MateriaAprobadaPtr matAprobada3 = crearMateriaAprobada(203, "Matematica", 9.0);
    MateriaAprobadaPtr matAprobada4 = crearMateriaAprobada(204, "Programacion", 6.5);
    MateriaAprobadaPtr matAprobada5 = crearMateriaAprobada(205, "Algebra", 7.5);
    MateriaAprobadaPtr matAprobada6 = crearMateriaAprobada(206, "Estadistica", 8.0);
    MateriaAprobadaPtr matAprobada7 = crearMateriaAprobada(207, "Biologia", 6.0);
    MateriaAprobadaPtr matAprobada8 = crearMateriaAprobada(208, "Historia", 9.5);
    MateriaAprobadaPtr matAprobada9 = crearMateriaAprobada(209, "Geografia", 7.8);
    MateriaAprobadaPtr matAprobada10 = crearMateriaAprobada(210, "Literatura", 8.3);
    ///AGREGARLES LAS MATERIAS APROBADAS A LOS ESTUDIANTES
    agregarMateriaAprobada(inscripto1, &matAprobada1);
    agregarMateriaAprobada(inscripto1, &matAprobada2);
    agregarMateriaAprobada(inscripto1, &matAprobada3);
    agregarMateriaAprobada(inscripto2, &matAprobada2);
    agregarMateriaAprobada(inscripto3, &matAprobada3);
    agregarMateriaAprobada(inscripto3, &matAprobada4);
    agregarMateriaAprobada(inscripto3, &matAprobada5);
    agregarMateriaAprobada(inscripto3, &matAprobada6);
    agregarMateriaAprobada(inscripto6, &matAprobada7);
    agregarMateriaAprobada(inscripto6, &matAprobada8);
    agregarMateriaAprobada(inscripto6, &matAprobada9);
    agregarMateriaAprobada(inscripto6, &matAprobada10);
    agregarMateriaAprobada(inscripto10, &matAprobada3);
    agregarMateriaAprobada(inscripto10, &matAprobada4);
    agregarMateriaAprobada(inscripto10, &matAprobada5);
    agregarMateriaAprobada(inscripto10, &matAprobada6);
    agregarMateriaAprobada(inscripto9, &matAprobada6);
    agregarMateriaAprobada(inscripto9, &matAprobada7);
    agregarMateriaAprobada(inscripto9, &matAprobada8);
    agregarMateriaAprobada(inscripto9, &matAprobada9);
    agregarMateriaAprobada(inscripto9, &matAprobada10);
    agregarMateriaAprobada(inscripto9, &matAprobada3);
    agregarMateriaAprobada(inscripto9, &matAprobada4);
    agregarMateriaAprobada(inscripto9, &matAprobada5);
    agregarMateriaAprobada(inscripto8, &matAprobada5);
    agregarMateriaAprobada(inscripto8, &matAprobada6);
    agregarMateriaAprobada(inscripto8, &matAprobada6);
    agregarMateriaAprobada(inscripto8, &matAprobada7);
    agregarMateriaAprobada(inscripto8, &matAprobada8);
    agregarMateriaAprobada(inscripto8, &matAprobada9);
    agregarMateriaAprobada(inscripto8, &matAprobada10);
    agregarMateriaAprobada(inscripto8, &matAprobada3);
    agregarMateriaAprobada(inscripto8, &matAprobada4);
    agregarMateriaAprobada(inscripto8, &matAprobada5);
    agregarMateriaAprobada(inscripto7, &matAprobada10);
    agregarMateriaAprobada(inscripto7, &matAprobada3);
    agregarMateriaAprobada(inscripto7, &matAprobada1);
    agregarMateriaAprobada(inscripto7, &matAprobada7);
    ///AGREGAR ESTUDIANTES A LAS MATERIAS
    agregarInscripto(materia1, &inscripto1);
    agregarInscripto(materia1, &inscripto2);
    agregarInscripto(materia1, &inscripto6);
    agregarInscripto(materia1, &inscripto10);
    agregarInscripto(materia1, &inscripto9);
    agregarInscripto(materia1, &inscripto8);
    agregarInscripto(materia1, &inscripto7);
    ///MOSTRAR
    mostrarMateria(materia1);

    ///SI NO HAY CUPO, LOS ESTUDIANTES QUEDAN EN UNA COLA DE ESPERA
    printf("---------------------------------------------\n");
    printf ("----LISTA DE ESPERA EN ORDEN PRIORITARIO-----\n");
    printf("---------------------------------------------\n");
    encolarElementos(getLista(materia1), getcola(materia1));
    ///DESENCOLAR LOS ELEMENTOS PARA MOSTRARLOS
    DatoPtr inscriptoPendiente;
    while ((inscriptoPendiente = desencolar(getcola(materia1))) != NULL) {
    mostrarInscriptoDatoPtr(inscriptoPendiente);
    }


}
