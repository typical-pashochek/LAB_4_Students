#include "Students_func.h"


//Ввод строки
char* Gets() {
	char* mass = (char*)malloc(51 * sizeof(char));
	char sym;
	int i = 0;
	sym = getchar();
	while (sym != '\n' && i < 50) {

		mass[i] = sym;
		sym = getchar();
		i += 1;
	}
	mass[i] = 0;
	char* mass_ = (char*)malloc((i + 1) * sizeof(char));
	for (int j = 0; j <= i; j++) {
		mass_[j] = mass[j];
	}
	free(mass);
	return mass_;

}
//Длина строки
int length(char str[]) {
	int n = 0;
	while (str[n] != '\0') {
		n = n + 1;
	}
	return n;
}

void outputStudent(Student* head) {
	if (head == 0) {
		printf("List is empty");
		return;
	}
	while (head->next != 0) {
		printf("%s\t", head->surname);
		if (length(head->name) > 7) {
			printf("%s\t", head->name);
		}
		else {
			printf("%s\t\t", head->name);
		}
		printf("%hi\t", head->age);
		printf("%s\t", head->group);
		printf("%s\t", head->phone);
		for (int i = 0; i < SIZE; i++) {
			printf("%hi", (head->marks)[i]);
		}
		head = head->next;
		printf("\n");
	}
	printf("%s\t", head->surname);
	if (length(head->name) > 7) {
		printf("%s\t", head->name);
	}
	else {
		printf("%s\t\t", head->name);
	}
	printf("%hi\t", head->age);
	printf("%s\t", head->group);
	printf("%s\t", head->phone);
	for (int i = 0; i < SIZE; i++) {
		printf("%hi", (head->marks)[i]);
	}
	printf("\n");
}
//Вывод одного студента по указателю на него
void outputOneStudent(Student* head) {
	if (head == 0) {
		printf("List is empty");
		return;
	}
	printf("%s\t", head->surname);
	if (length(head->name) > 7) {
		printf("%s\t", head->name);
	}
	else {
		printf("%s\t\t", head->name);
	}
	printf("%hi\t", head->age);
	printf("%s\t", head->group);
	printf("%s\t", head->phone);
	for (int i = 0; i < SIZE; i++) {
		printf("%hi", (head->marks)[i]);
	}
	printf("\n");
}
//Добавление студента - ввод с клавиатуры
void addStudent(Student* head) {
	if (head->next == 0 && (head->age < 18 || head->age > 30)) {
		head->surname = Gets();
		head->name = Gets();
		scanf_s("%hi", &(head->age));
		getchar();
		head->group = Gets();
		head->phone = Gets();
		for (int i = 0; i < SIZE; i++) {
			scanf_s("%hi", &(head->marks[i]));
		}
		return;
	}
	while (head->next != 0)
		head = head->next;

	head->next = (Student*)malloc(sizeof(Student));
	head->next->surname = Gets();
	head->next->name = Gets();
	scanf_s("%hi", &(head->next->age));
	getchar();
	head->next->group = Gets();
	head->next->phone = Gets();
	for (int i = 0; i < SIZE; i++) {
		scanf_s("%hi", &(head->next->marks[i]));
	}
	head->next->next = 0;
}
//Рандомное добавление студента
void addStudent_Random(Student* head, char*** names, char*** surnames, char*** phones, char*** groups) {
	int i = rand() % COUNT;
	if (head->next == 0 && (head->age < 18 || head->age > 30)) {
		head->surname = (*surnames)[i];
		i = rand() % COUNT;
		head->name = (*names)[i];
		head->age = (short)(rand() % 10 + 18);
		i = rand() % COUNT;
		head->group = (*groups)[i];
		i = rand() % COUNT;
		head->phone = (*phones)[i];
		for (int j = 0; j < SIZE; j++) {
			head->marks[j] = (short)(rand() % 3 + 3);
		}
		return;
	}
	while (head->next != 0)
		head = head->next;

	head->next = (Student*)malloc(sizeof(Student));
	head->next->surname = (*surnames)[i];
	i = rand() % COUNT;
	head->next->name = (*names)[i];
	head->next->age = (short)(rand() % 10 + 18);
	i = rand() % COUNT;
	head->next->group = (*groups)[i];
	i = rand() % COUNT;
	head->next->phone = (*phones)[i];
	for (int j = 0; j < SIZE; j++) {
		head->next->marks[j] = (short)(rand() % 3 + 3);
	}
	head->next->next = 0;
}
//Функция переводящая текстовый файл в массив строк
void TextIntoMass(char*** mass, FILE** Text, int* rowsCount) {
	char symbol;
	symbol = fgetc(*Text);
	int rows = 2;
	while (!feof(*Text)) {
		if (symbol == '\n') {
			rows += 1;
		}
		symbol = fgetc(*Text);
	}
	*rowsCount = rows - 1;
	fseek(*Text, 0, SEEK_SET);
	(*mass) = (char**)malloc(rows * sizeof(char*));
	for (int i = 0; i < rows; i++) {
		int count = 0;
		symbol = fgetc(*Text);
		while (symbol != '\n' && !feof(*Text)) {
			count += 1;
			symbol = fgetc(*Text);
		}
		if (symbol == '\n') {
			fseek(*Text, -(count + 2), SEEK_CUR);
		}
		else {
			fseek(*Text, -(count), SEEK_CUR);
		}
		(*mass)[i] = (char*)malloc((count + 2) * sizeof(char));
		fgets((*mass)[i], count + 1, *Text);
		fgetc(*Text);
		(*mass)[i][count + 1] = 0;
	}
}
//Функция заполняющая массивы, необходимые для рандомного ввода
void GetRandomInfo(char*** names, char*** surnames, char*** phones, char*** groups) {
	FILE* file;
	fopen_s(&file, "surnames.txt", "r");
	int len;
	if (file != NULL) {
		TextIntoMass(surnames, &file, &len);
	}
	fclose(file);
	fopen_s(&file, "names.txt", "r");
	if (file != NULL) {
		TextIntoMass(names, &file, &len);
	}
	fclose(file);
	fopen_s(&file, "phones.txt", "r");
	if (file != NULL) {
		TextIntoMass(phones, &file, &len);
	}
	fclose(file);
	fopen_s(&file, "groups.txt", "r");
	if (file != NULL) {
		TextIntoMass(groups, &file, &len);

	}
	fclose(file);
}
//Одинаковые ли строки?
int SameStrings(char** first, char** second) {
	int flag;
	if (length(*first) == length(*second)) {
		int len = length(*second);
		for (int i = 0; i < len; i++) {
			if ((*first)[i] != (*second)[i]) {
				flag = 0;
				break;
			}
			if (i == len - 1) {
				flag = 1;
			}
		}
	}
	else {
		flag = 0;
	}
	return flag;
}


//Успевающий ли студент?
int IsAchiever(Student* head) {
	float sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += head->marks[i];
	}
	sum = sum / SIZE;
	//printf("SUM  %f\n", sum);
	if (sum < 4) {
		return 0;
	}
	else {
		return 1;
	}
}
//Удаление студента по указателю на него
void DeleteStudent(Student** head, Student* del) {
	Student* ptr;
	Student* head_ = (*head);
	if (head_ == del) {
		ptr = (*head);
		(*head) = (*head)->next;
		free(ptr);
		return;
	}

	while (head_->next != del && head_->next != 0) {
		head_ = head_->next;
	}
	if (head_->next == del) {
		ptr = head_->next;
		//free(head_);
		head_->next = head_->next->next;
		free(ptr);
	}

}
//Удаление студентов по фамилии
void DeleteStudent_Surname(Student** head, char** surname) {
	Student* ptr;
	Student* ptr2;
	ptr = (*head);
	while (ptr->next != 0) {
		if (SameStrings(&(ptr->surname), surname)) {
			ptr2 = ptr->next;
			DeleteStudent(head, ptr);
			ptr = ptr2;
		}
		else {
			ptr = ptr->next;
		}
		if (ptr == 0) {
			return;
		}
	}
	if (SameStrings(&(ptr->surname), surname)) {
		ptr2 = ptr->next;
		DeleteStudent(head, ptr);
		ptr = ptr2;
	}
}
//Удаление неуспевающих студентов
void DeleteStudent_Marks(Student** head) {
	Student* ptr;
	Student* ptr2;
	ptr = (*head);
	while (ptr->next != 0) {
		if (!IsAchiever(ptr)) {
			ptr2 = ptr->next;
			DeleteStudent(head, ptr);
			ptr = ptr2;
		}
		else {
			ptr = ptr->next;
		}
		if (ptr == 0) {
			return;
		}
	}
	if (!IsAchiever(ptr)) {
		ptr2 = ptr->next;
		DeleteStudent(head, ptr);
		ptr = ptr2;
	}
}
//Удаление студента по номеру в списке. Нумерация с 1
void DeleteStudent_Number(Student** head, int i) {
	Student* ptr;
	Student* ptr2;
	ptr = (*head);
	int j = 1;
	while (ptr->next != 0) {
		if (j == i) {
			ptr2 = ptr->next;
			DeleteStudent(head, ptr);
			ptr = ptr2;
			return;
		}
		else {
			j += 1;
			ptr = ptr->next;
		}
		if (ptr == 0) {
			return;
		}
	}
	if (i == j) {
		ptr2 = ptr->next;
		DeleteStudent(head, ptr);
		ptr = ptr2;
	}
}
//Вывод успевающих студентов
void OutputAchievers(Student* head) {
	if (head == 0) {
		printf("List is empty");
		return;
	}
	while (head->next != 0) {
		if (IsAchiever(head)) {
			outputOneStudent(head);
		}
		head = head->next;
	}
	if (IsAchiever(head)) {
		outputOneStudent(head);
	}

}
//Вывод одногруппников
void OutputGroupmates(Student* head, char** group) {
	if (head == 0) {
		printf("List is empty");
		return;
	}
	while (head->next != 0) {
		if (SameStrings(&(head->group), group)) {
			outputOneStudent(head);
		}
		head = head->next;
	}
	if (SameStrings(&(head->group), group)) {
		outputOneStudent(head);
	}

}
//Начинается ли слово с определеных букв?
int SameBeginning(char** first, char** second) {
	int flag;
	if (length(*first) >= length(*second)) {
		int len = length(*second);
		for (int i = 0; i < len; i++) {
			if ((*first)[i] != (*second)[i]) {
				flag = 0;
				break;
			}
			if (i == len - 1) {
				flag = 1;
			}
		}
	}
	else {
		flag = 0;
	}
	return flag;
}
//Вывод студентов с одинаково начинающимися фамилиями
void OutputStudent_SurnameBeginning(Student* head, char** begin) {
	if (head == 0) {
		printf("List is empty");
		return;
	}
	while (head->next != 0) {
		if (SameBeginning(&(head->surname), begin)) {
			outputOneStudent(head);
		}
		head = head->next;
	}
	if (SameBeginning(&(head->surname), begin)) {
		outputOneStudent(head);
	}
}
//Извлечение слова из строки
char* GetWord(char** mass, int* i) {
	int len = length(*mass);
	char* word;
	while ((*mass)[*i] == ' ' && *i < len) {
		*i += 1;
	}
	int begin = *i;
	while ((*mass)[*i] != ' ' && *i < len) {
		*i += 1;
	}
	word = (char*)malloc((*i + 1 - begin) * sizeof(char));
	for (int j = begin; j < *i; j++) {
		word[j - begin] = (*mass)[j];
	}
	word[*i - begin] = 0;
	return word;
}
//перевод строки в число
int GetDigit(char** mass) {
	int res = 0;
	int len = length(*mass);
	for (int i = 0; i < len; i++) {
		res = res * 10 + (int)(*mass)[i] - 48;
	}
	return res;
}
//Ввод студентов из текстового файла
void addStudent_TXT(FILE** f, Student* head) {
	char** mass;
	int rows;
	TextIntoMass(&mass, f, &rows);
	for (int i = 0; i < rows; i++) {
		if (head->next == 0 && (head->age < 18 || head->age > 30)) {
			int j = 0;
			head->surname = GetWord(&(mass[i]), &j);
			head->name = GetWord(&(mass[i]), &j);
			char* digit = GetWord(&(mass[i]), &j);
			head->age = GetDigit(&digit);
			free(digit);
			head->group = GetWord(&(mass[i]), &j);
			head->phone = GetWord(&(mass[i]), &j);
			digit = GetWord(&(mass[i]), &j);
			for (int k = 0; k < SIZE; k++) {
				head->marks[k] = (short)digit[k] - 48;
			}
			free(digit);
			continue;
		}
		while (head->next != 0)
			head = head->next;
		head->next = (Student*)malloc(sizeof(Student));
		int j = 0;
		head->next->surname = GetWord(&(mass[i]), &j);
		head->next->name = GetWord(&(mass[i]), &j);
		char* digit = GetWord(&(mass[i]), &j);
		head->next->age = GetDigit(&digit);
		free(digit);
		head->next->group = GetWord(&(mass[i]), &j);
		head->next->phone = GetWord(&(mass[i]), &j);
		digit = GetWord(&(mass[i]), &j);
		for (int k = 0; k < SIZE; k++) {
			head->next->marks[k] = (short)digit[k] - 48;
		}
		free(digit);
		head->next->next = 0;
	}
}
//Вывод студентов в текстовый файл 
void outputStudent_TXT(FILE** f, Student* head) {
	if (head == 0) {
		printf("List is empty");
		return;
	}
	while (head->next != 0) {
		fprintf(*f, "%s\t", head->surname);
		if (length(head->name) > 7) {
			fprintf(*f, "%s\t", head->name);
		}
		else {
			fprintf(*f, "%s\t\t", head->name);
		}
		fprintf(*f, "%hi\t", head->age);
		fprintf(*f, "%s\t", head->group);
		fprintf(*f, "%s\t", head->phone);
		for (int i = 0; i < SIZE; i++) {
			fprintf(*f, "%hi", (head->marks)[i]);
		}
		head = head->next;
		fprintf(*f, "\n");
	}
	fprintf(*f, "%s\t", head->surname);
	if (length(head->name) > 7) {
		fprintf(*f, "%s\t", head->name);
	}
	else {
		fprintf(*f, "%s\t\t", head->name);
	}
	fprintf(*f, "%hi\t", head->age);
	fprintf(*f, "%s\t", head->group);
	fprintf(*f, "%s\t", head->phone);
	for (int i = 0; i < SIZE; i++) {
		fprintf(*f, "%hi", (head->marks)[i]);
	}
	fprintf(*f, "\n");
}
//Вывод студентов в бинарный файл
void outputStudent_BIN(FILE* output, Student* head) {
	if (head == 0) {
		printf("List is empty");
		return;
	}
	while (head->next != 0) {
		int len = length(head->surname);
		fwrite(&len, sizeof(int), 1, output);
		fwrite((head->surname), sizeof(char), length(head->surname), output);
		len = length(head->name);
		fwrite(&len, sizeof(int), 1, output);
		fwrite((head->name), sizeof(char), length(head->name), output);
		fwrite(&(head->age), sizeof(short), 1, output);
		len = length(head->group);
		fwrite(&len, sizeof(int), 1, output);
		fwrite((head->group), sizeof(char), length(head->group), output);
		len = length(head->phone);
		fwrite(&len, sizeof(int), 1, output);
		fwrite((head->phone), sizeof(char), length(head->phone), output);
		fwrite((head->marks), sizeof(short), SIZE, output);
		head = head->next;
	}
	int len = length(head->surname);
	fwrite(&len, sizeof(int), 1, output);
	fwrite((head->surname), sizeof(char), length(head->surname), output);
	len = length(head->name);
	fwrite(&len, sizeof(int), 1, output);
	fwrite((head->name), sizeof(char), length(head->name), output);
	fwrite(&(head->age), sizeof(short), 1, output);
	len = length(head->group);
	fwrite(&len, sizeof(int), 1, output);
	fwrite((head->group), sizeof(char), length(head->group), output);
	len = length(head->phone);
	fwrite(&len, sizeof(int), 1, output);
	fwrite((head->phone), sizeof(char), length(head->phone), output);
	fwrite((head->marks), sizeof(short), SIZE, output);

}
//Добавление студентов из бинарного файла
void addStudent_BIN(FILE* input, Student* head) {
	int flag = 1;
	while (!feof(input)) {
		fgetc(input);
		if (feof(input)) {
			break;
		}
		fseek(input, -1, SEEK_CUR);
		if (flag != 1) {
			head->next = (Student*)malloc(sizeof(Student));
			head->next->next = 0;
			head = head->next;
		}
		int i;

		fread(&i, sizeof(int), 1, input);

		head->surname = (char*)malloc((i + 1) * sizeof(char));
		fread(head->surname, sizeof(char), i, input);
		head->surname[i] = 0;

		fread(&i, sizeof(int), 1, input);
		head->name = (char*)malloc((i + 1) * sizeof(char));
		fread(head->name, sizeof(char), i, input);
		head->name[i] = 0;
		fread(&(head->age), sizeof(short), 1, input);
		fread(&i, sizeof(int), 1, input);
		head->group = (char*)malloc((i + 1) * sizeof(char));
		fread(head->group, sizeof(char), i, input);
		head->group[i] = 0;
		fread(&i, sizeof(int), 1, input);
		head->phone = (char*)malloc((i + 1) * sizeof(char));
		fread(head->phone, sizeof(char), i, input);
		head->phone[i] = 0;
		fread(head->marks, sizeof(short), SIZE, input);
		flag += 1;

	}
}
//Очищение списка студентов
void FreeStudents(Student** s1) {
	Student* head = *s1;
	while ((*s1)->next != 0) {
		*s1 = (*s1)->next;
		free(head);
		head = *s1;
	}
	*s1 = (*s1)->next;
	free(head);
}