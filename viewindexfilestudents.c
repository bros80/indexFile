/* Copyrigth (c) 2020 Run 2 Run Software
   Programa para visualizar el archivo índice de estudiantes */

#include <stdio.h>
#include "student.h"
#include "student.c"

void main () {
	printf ("\n\nPrograma para visualizar el archivo índice");
	printf ("\nPresione una tecla para comenzar...");
	getchar ();
	
	if (viewIndexFileStudents () == DONE)
		printf ("\n\nPrograma terminado con éxito!\n\n");
	else
		printf ("\n\n¡Ups! El programa falló\n\n");
}

int viewIndexFileStudents () {
	FILE* findex = fopen (FILENAME_INDEX, "r");

	if (findex == NULL) 
		return ERR_OPENFILE_FAIL;

	Index record;
	int count = 0;
	while (
		fread (&record, sizeof (Index), READED_RECORDS, findex) 
			== READED_RECORDS) {
		printf ("%i.%s\n", ++count, record.field);
	}
	fclose (findex);

	return DONE;
}
