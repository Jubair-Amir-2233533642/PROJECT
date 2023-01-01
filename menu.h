#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Structure of the worker
struct worker{
	char name[50];
	float wage;
	int age;
	int id;
};
struct worker w;

// size of the structure
long int size = sizeof(w);

// In the start coordinates will be 0, 0
COORD cord = { 0, 0 };

// function to set the coordinates
void coorxy(int x, int y)
{
	cord.X = x;
	cord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cord);
}

FILE* fp, * ft;

// Function to add the records
void addtolist()
{
	system("cls");
	fseek(fp, 0, SEEK_END);
	char another = 'y';

	while (another == 'y'||another == 'Y') {
		printf("\nEnter Name : ");
		scanf("%s", &w.name);

		printf("\nEnter Age : ");
		scanf("%d", &w.age);

		printf("\nEnter Wage : ");
		scanf("%f", &w.wage);

		printf("\nEnter ID : ");
		scanf("%d", &w.id);

		fwrite(&w, size, 1, fp);

		printf("\nWant to add another");
			printf(" record (Y/N) : ");
		fflush(stdin);

		scanf("%c", &another);
	}
}

// Function to delete the records
void delfromlist()
{
	system("cls");
	char worname[50];
	char another = 'y';

	while (another == 'y'||another == 'Y') {
		printf("\nEnter worker's ");
			printf("name to delete : ");
		scanf("%s", worname);

		ft = fopen("temp.txt", "wb");
		rewind(fp);

		while (fread(&w, size,1, fp)== 1) {
			if (strcmp(w.name,worname)!= 0)
				fwrite(&w, size, 1, ft);
		}

		fclose(fp);
		fclose(ft);
		remove("data.txt");
		rename("temp.txt", "data.txt");
		fp = fopen("data.txt", "rb+");

		printf("\nWant to delete another");
			printf(" record (Y/N) :");
		fflush(stdin);
		another = getchar();
	}
}

// Function to display the record
void showlist()
{
	system("cls");

	// sets pointer to start
	// of the file
	rewind(fp);

	printf("\n==========================================================");
	printf("\nNAME\t\tAGE\t", w.name, w.age);
	printf("\tWAGE\t\tID\n",w.wage, w.id);
	printf("==========================================================\n");

	while (fread(&w, size, 1, fp) == 1)
		printf("\n%s\t\t%d\t\t%.2f\t%10d",
			w.name, w.age, w.wage, w.id);

	printf("\n\n\n\t");
	system("pause");
}

// Function to modify the record
void editlist()
{
	system("cls");
	char worname[50];
	char another = 'y';

	while (another == 'y'||another == 'Y') {
		printf("\nEnter Worker's name to modify : ");
		scanf("%s", worname);

		rewind(fp);

		// While File is open
		while (fread(&w, size, 1, fp) == 1) {
			// Compare the worker name
			// with ename
			if (strcmp(w.name, worname) == 0) {
				printf("\nEnter new name:");
				scanf("%s", w.name);
				printf("\nEnter new age :");
				scanf("%d", &w.age);
				printf("\nEnter new wage :");
				scanf("%f", &w.wage);
				printf("\nEnter new ID :");
				scanf("%d", &w.id);

				fseek(fp, -size, SEEK_CUR);
				fwrite(&w, size, 1, fp);
				break;
			}
		}

		// Ask for modifying another record
		printf("\nWant to modify another record (Y/N) :");
		fflush(stdin);
		scanf("%c", &another);
	}
}
