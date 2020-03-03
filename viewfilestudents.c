/* Copyrigth (c) 2020 Run 2 Run Software
   Programa para visualizar el archivo de registros de estudiantes */

#include <stdio.h>
#include "student.h"
#include "student.c"

void main () {
	printf ("\n\nPrograma para visualizar el archivo de registro");
	printf ("\nPresione una tecla para comenzar...");
	getchar ();
	
	if (viewFileStudents () == DONE)
		printf ("\n\nPrograma terminado con éxito!\n\n");
	else
		printf ("\n\n¡Ups! El programa falló\n\n");
}

int viewFileStudents () {
	FILE* fstudent = fopen (FILENAME_STUDENT, "r");

	if (fstudent == NULL) 
		return ERR_OPENFILE_FAIL;

	Student record;
	const char* HEADERS[] = { 
		"APELLIDO", "NOMBRE", "DIRECCIÓN", "TELÉFONO", "CIUDAD" };

	printf ("%-15s%-15s%-25s%-10s%-20s\n",
		HEADERS[0], HEADERS[1], HEADERS[2], HEADERS[3], HEADERS[4]);
	while (
		fread (&record, sizeof (Student), READED_RECORDS, fstudent) 
			== READED_RECORDS) {
		showStudent (record);
	}
	fclose (fstudent);

	return DONE;
}

void showStudent (Student student) {
	printf ("%-15s%-15s%-25s%-10s%-20s\n", 
		student.surname, student.name, 
		student.address, student.telephone, student.city);
}
