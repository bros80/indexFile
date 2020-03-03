/* Copyrigth (c) 2020 Run 2 Run Software
   Programa para testear  */

#include <stdio.h>
#include "student.h"
#include "student.c"

void main () {
	printf ("\n\nTesteando\n");
	getchar ();

	// Sólo se tiene que llamar una vez
	srand (time (NULL));
	char* cities[] = {
		"C. Paz", "Cba.", "A. Gracia", "Río IV", "Calera",
		"Arroyito", "San Fco.", "Belville", "Morteros", "Elena" };
	int i;
	for (i = 0; i < 20; i++)
		//printf ("%s\n", cities[rand() % 10]);
		printf ("%s\n", randomValue (cities));
}
