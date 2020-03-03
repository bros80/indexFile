/* Copyrigth (c) 2020 Run 2 Run Software
   Programa para buscar un dato en el archivo de registros */

#include <stdio.h>
#include "student.h"
#include "student.c"

void main () {
	char datFind[MAXLEN * 2];

	printf ("\n\nPrograma para buscar un dato en el archivo de registro");
	printf ("\nIngrese el dato: ");
	gets (datFind);
	
	printf ("\nBuscando %s...", datFind);
	char result[MAXLEN * 2];
	strcpy (result, findStudentInIndex (datFind));
	if (strlen (result) != 0)
		printf ("\n¡Su dirección es %s!\n\n", result);
	else
		printf ("\n¡Ups! El dato no esta\n\n");
}
