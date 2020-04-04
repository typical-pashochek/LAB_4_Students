#ifndef Students_func
#define Students_func
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#define SIZE 10 //Количество оценок

#define COUNT 50 //Количество фамилий, имён, групп, телефонов, доступных для рандомного ввода

struct Student {
	char* surname;
	char* name;
	short age;
	char* group;
	char* phone;
	short marks[SIZE];
	struct Student* next;
};

typedef struct Student Student;
char* Gets();
int length(char str[]); 
void outputStudent(Student* head);
void outputOneStudent(Student* head);
void addStudent(Student* head);
void addStudent_Random(Student* head, char*** names, char*** surnames, char*** phones, char*** groups);
void TextIntoMass(char*** mass, FILE** Text, int* rowsCount);
void GetRandomInfo(char*** names, char*** surnames, char*** phones, char*** groups);
int SameStrings(char** first, char** second);
int IsAchiever(Student* head);
void DeleteStudent(Student** head, Student* del);
void DeleteStudent_Surname(Student** head, char** surname);
void DeleteStudent_Marks(Student** head);
void DeleteStudent_Number(Student** head, int i);
void OutputAchievers(Student* head);
void OutputGroupmates(Student* head, char** group);
int SameBeginning(char** first, char** second);
void OutputStudent_SurnameBeginning(Student* head, char** begin);
char* GetWord(char** mass, int* i);
int GetDigit(char** mass);
void addStudent_TXT(FILE** f, Student* head);
void outputStudent_TXT(FILE** f, Student* head);
void outputStudent_BIN(FILE* output, Student* head);
void addStudent_BIN(FILE* input, Student* head);
void FreeStudents(Student** s1);
#endif