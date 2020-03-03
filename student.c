/* Copyrigth (c) 2020 Run 2 Run Software
   Archivo de implementación de "student.h" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"

char* findStudentInIndex (char* student) {
	FILE* findex = fopen (FILENAME_INDEX, "r");
	char* fail = { "" };

	if (findex == NULL) 		
		return fail;

	Index record;
	int count = 0;
	while (
		fread (&record, sizeof (Index), READED_RECORDS, findex)
			== READED_RECORDS) {
		if (strcmp (student, record.field) == 0) {
			printf ("%s encontrado!", record.field);
			fclose (findex);
			return findStudentInFile (count);
		}
		count++;
	}
	fclose (findex);

	return fail;
}

char* findStudentInFile (int location) {
	FILE* fstudent = fopen (FILENAME_STUDENT, "r");

	if (fstudent == NULL) {
		char* fail = { "" };
		return fail;
	}

	Student record;
	fseek (fstudent, (long int) sizeof (Student) * location, SEEK_SET);
	fread (&record, sizeof (Student), READED_RECORDS, fstudent);
	fclose (fstudent);

	char* field = malloc (MAXLEN * 2);
	strcpy (field, record.address);
	return field;
}

int createIndexFileStudents () {
	FILE* fstudent = fopen (FILENAME_STUDENT, "r");
	FILE* findex = fopen (FILENAME_INDEX, "w");

	if (fstudent == NULL) {
		return ERR_OPENFILE_FAIL;
	}
	if (findex == NULL) {
		fclose (fstudent);
		return ERR_OPENFILE_FAIL;
	}

	Student recStudent;
	Index recIndex;
	while (
		fread (&recStudent, sizeof (Student), READED_RECORDS, fstudent)
			== READED_RECORDS) {
		strcpy (recIndex.field, 
			genField( recStudent.name, recStudent.surname));			
		fwrite (&recIndex, sizeof (Index), 1, findex);
	}
	fclose (fstudent);
	fclose (findex);

	return DONE;
}

const char* genField (char* name, char* surname) {
	char* field = malloc (MAXLEN * 2);
	
	strcpy (field, "");
	strcat (field, surname);
	strcat (field, " ");
	strcat (field, name);
	return field;
}

int orderIndexFileStudents () {
	FILE* findex = fopen (FILENAME_INDEX, "r+");

	if (findex == NULL)
		return ERR_OPENFILE_FAIL;

	Index record,
		recordaux;
	long int offset = 0L,
		sizeFile = 0L;
	fseek (findex, 0, SEEK_END);
	sizeFile = ftell (findex);
	fseek (findex, 0, SEEK_SET);
	while (
		fread (&record, sizeof (Index), READED_RECORDS, findex)
			== READED_RECORDS && offset < sizeFile) {
		while (
			fread (&recordaux, sizeof (Index), READED_RECORDS, findex)
				== READED_RECORDS) {
			if (strcmp (recordaux.field, record.field) < 0) {
				long int last = ftell (findex);
				fseek (findex, -(sizeof (Index)), SEEK_CUR);
				fwrite (&record, sizeof (Index), READED_RECORDS, findex);
				fseek (findex, offset, SEEK_SET);
				fwrite (&recordaux, sizeof (Index), READED_RECORDS, findex);
				fseek (findex, last, SEEK_SET);
				Index temp = record;
				record = recordaux;
				recordaux = temp;
			}	
		}
		offset += sizeof (Index);
		fseek (findex, offset, SEEK_SET);
		if (offset == (sizeFile - sizeof (Index)))
			break;
	}
	fclose (findex);

	return DONE;
}

int createFileStudents () {
	FILE* fstudent = fopen (FILENAME_STUDENT, "w");
	
	if (fstudent == NULL)
		return ERR_OPENFILE_FAIL;

	// Sólo se tiene que llamar una vez
	srand (time (NULL));
	int i;
	for (i = 0; i < MAXREG; i++) {
		Student student = createRecord ();
		fwrite (&student, sizeof (Student), 1, fstudent);
	}
	fclose (fstudent);

	return DONE;
}

Student createRecord () {
	Student stden;

	strcpy (stden.name, genName ());
	strcpy (stden.surname, genSurname ());
	strcpy (stden.address, genAddress ());
	strcpy (stden.telephone, genTelephone ());
	strcpy (stden.city, genCity ());

	return stden;
}

char* genName () {
	char* names[] = {
		"Raúl", "Dana", "Ema", "José", "Ana", 
		"Luis", "Pedro", "Juan", "Rosa", "Bruno" };
	return randomValue (names);
}

char* genSurname () {
	char* surnames[] = {
		"Fox", "Gil", "Roy", "Coss", "Luna",
		"Rojo", "Vega", "Monti", "Juez", "Marzo" };
	return randomValue (surnames);
}

char* genAddress () {
	char* address[] = { 
		"Colón 348", "Sucre 221", "Drago 1876", "G. Paz 15", "Brasil 32",
		"Maipú 234", "Tacna 1900", "Pje. 12 99", "Antún 291", "López 566" };
	return randomValue (address);
}

char* genTelephone () {
	char* tels[] = {
		"4568457", "4231565", "459852", "4236584", "4328751",
		"4536998", "4251175", "433251", "4612217", "4611873" };
	return randomValue (tels);
}

char* genCity () {
	char* cities[] = {
		"C. Paz", "Cba.", "A. Gracia", "Río IV", "Calera",
		"Arroyito", "San Fco.", "Belville", "Morteros", "Elena" };
	return randomValue (cities);
}

char* randomValue (char* values[]) {
	const int LEN_VALUES = 10;

	return values[rand() % LEN_VALUES];
}
