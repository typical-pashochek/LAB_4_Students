#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "Students_func.h"


int main() {
	srand((unsigned int)time(NULL));
	char** surnames;
	char** names;
	char** phones;
	char** groups;
	setlocale(LC_ALL, "rus");
	GetRandomInfo(&names, &surnames, &phones, &groups);
	Student* s1 = (Student*)malloc(sizeof(Student));
	s1->next = 0;
	for (int i = 0; i < 15; i++) {
		addStudent_Random(s1, &names, &surnames, &phones, &groups);
	}
	outputStudent(s1);
	printf("CHANGING\n");
	FreeStudents(&s1);
	outputStudent(s1);
	return 0;
}