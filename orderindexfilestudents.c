/* Copyrigth (c) 2020 Run 2 Run Software
   Programa para el ordenamiento del archivo indice de estudiantes */

#include <stdio.h>
#include "student.h"
#include "student.c"

void main () {
	printf ("\n\nPrograma para ordenar el archivo índice");
	printf ("\nPresione una tecla para comenzar...");
	getchar ();
	
	orderIndexFileStudents ();
    printf ("\n\nPrograma terminado con éxito!\n\n");
}
