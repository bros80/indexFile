/* Copyrigth (c) 2020 Run 2 Run Software
   Programa para generar el archivo índice de estudiantes */

#include <stdio.h>
#include "student.h"
#include "student.c"

void main () {
	printf ("\n\nPrograma para generar el archivo índice");
	printf ("\nPresione una tecla para comenzar...");
	getchar ();
	
	if (createIndexFileStudents () == DONE)
		printf ("\n\nPrograma terminado con éxito!\n\n");
	else
		printf ("\n\n¡Ups! El programa falló\n\n");
}
