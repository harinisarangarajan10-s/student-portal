#include <stdio.h>
#include "student.h"
#include"file.h"


int main(void)
{
    int choice;
    loadRecords();

    while (1)
    {
        printf("\n");
        printf("============================================\n");
        printf("         STUDENT RECORD MANAGER\n");
        printf("============================================\n");

        printf("1. Add Student\n");
	printf("2. Display Students\n");
	printf("3. Search Student\n");
	printf("4. Update Student\n");
	printf("5. Delete Student\n");
	printf("6. Sort Students\n");
	printf("7. Save Records\n");
	printf("8. Exit\n");

        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                sortStudents();
                break;

           case 7:
    		saveRecords();
   		 break;

	   case 8:
    		printf("\nExiting Student Record Manager...\n");
    		return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}