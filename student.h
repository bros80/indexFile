/* Copyrigth (c) 2020 Run 2 Run Software
   Archivo de cabecera "student.h" */

#ifndef __STUDENT_H__
#define __STUDENT_H__

#define MAXLEN 24
#define MAXREG 10000
#define FILENAME_STUDENT "student.dat"
#define FILENAME_INDEX "student.idx"
#define ERR_OPENFILE_FAIL -1
#define DONE 0
#define READED_RECORDS 1

typedef struct student {
	char studentId[MAXLEN];
	char name[MAXLEN];
	char surname[MAXLEN];
	char address[MAXLEN];
	char telephone[MAXLEN];
	char city[MAXLEN];
} Student;

typedef struct index {
	char field[MAXLEN * 2];
} Index;

char* findStudentInFile (int );
char* findStudentInIndex (char* );
int createIndexFileStudents ();
const char* genField (char* , char* );
int orderIndexFileStudents ();
void compareField (FILE* , FILE* , Index , Index );
int createFileStudents ();
int viewFileStudents ();
Student createRecord ();
char* genName ();
char* genSurname ();
char* genAddress ();
char* genTelephone ();
char* genCity ();
char* randomValue (char* []);
void showStudent (Student );

#endif
