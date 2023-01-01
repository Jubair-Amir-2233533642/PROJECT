#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include "login.h"
#include"menu.h"
#include"splash.h"
#define size 20

int main()
{
	int choice;

	// opening the file
	fp = fopen("data.txt", "rb+");

	// showing error if file is
	// unable to open.
	if (fp == NULL) {
		fp = fopen("data.txt", "wb+");
		if (fp == NULL) {
			printf("\nCannot open file...");
			exit(1);
		}
	}

	system("Color 5F");
	splash1();
	splash2();
	login();
	printf("\n\n\n\t\t\t\t\t");
	printf("NAME: JUBAIR AMIR\n");
	printf("\n\n\t\t\t\t\t");
	printf("ID: 2233533642");
	printf("\n\n\t\t\t\t\t");
	printf("FACULTY: MLE");
    printf("\n\n\t\t\t\t");

	system("pause");

	while (1) {
		// Clearing console and asking the user for input
		system("cls");
		coorxy(30, 10);
		printf("\n1. ADD TO LIST\n");
		coorxy(30, 12);
		printf("\n2. DELETE FROM LIST\n");
		coorxy(30, 14);
		printf("\n3. SHOW LIST\n");
		coorxy(30, 16);
		printf("\n4. EDIT LIST\n");
		coorxy(30, 18);
		printf("\n5. EXIT\n");
		coorxy(30, 20);
		printf("\nENTER YOUR CHOICE...\n");
		fflush(stdin);
		scanf("%d", &choice);


		switch (choice) {
		case 1:


			addtolist();
			break;

		case 2:


			delfromlist();
			break;

		case 3:


			showlist();
			break;

		case 4:


			editlist();
			break;

		case 5:
			fclose(fp);
			exit(0);
			break;

		default:
			printf("\nINVALID CHOICE...CHECK AGAIN.....\n");
		}
	}

	return 0;
}
