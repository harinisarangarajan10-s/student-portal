#include <stdio.h>
#include<string.h>
#include "student.h"

struct Student students[MAX_STUDENTS];
int count = 0;


void generateRegNo(char reg_no[])
{
    int i;
    int number;
    int max_number = 0;
    char dept[4] = {0};

    for (i = 0; i < count; i++)
    {
        if (sscanf(students[i].reg_no, "%*[^0-9]%*2d%*[^0-9]%d", &number) == 1)
        {
            if (number > max_number)
            {
                max_number = number;
            }
        }
    }

    for (i = 0; i < 3 && students[count].department[i] != '\0'; i++)
    {
        dept[i] = students[count].department[i];

        if (dept[i] >= 'a' && dept[i] <= 'z')
        {
            dept[i] = dept[i] - 'a' + 'A';
        }
    }

    sprintf(reg_no, "%c%02d%s%03d",
            students[count].name[0],
            students[count].admission_year % 100,
            dept,
            max_number + 1);
}


void addStudent(void)
{
    if (count >= MAX_STUDENTS)
    {
        printf("\nStudent record is full!\n");
        return;
    }

    printf("\n========== ADD STUDENT ==========\n");

    printf("Enter Name           : ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Admission Year : ");
    scanf("%d", &students[count].admission_year);

    printf("Enter Age            : ");
    scanf("%d", &students[count].age);

    printf("Enter Department     : ");
    scanf(" %[^\n]", students[count].department);

    printf("Enter Marks          : ");
    scanf("%f", &students[count].marks);

    generateRegNo(students[count].reg_no);

    printf("\nStudent added successfully!\n");
    printf("Student ID : %s\n", students[count].reg_no);

    count++;
}




void displayStudents(void)
{
    int i;

    if (count == 0)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n");
    printf("+-------------+----------------------+-----+------+----------------+--------+\n");
    printf("| Student ID  | Name                 | Age | Year | Department     | Marks  |\n");
    printf("+-------------+----------------------+-----+------+----------------+--------+\n");

    for (i = 0; i < count; i++)
    {
        printf("| %-11s | %-20s | %-3d | %-4d | %-14s | %-6.2f |\n",
               students[i].reg_no,
               students[i].name,
               students[i].age,
               students[i].admission_year,
               students[i].department,
               students[i].marks);
    }

    printf("+-------------+----------------------+-----+------+----------------+--------+\n");
}

void searchStudent(void)
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("====================================\n");
        printf("          SEARCH STUDENT\n");
        printf("====================================\n");
        printf("1. Search by Name\n");
        printf("2. Search by Registration Number\n");
        printf("3. Back\n");
        printf("====================================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                searchByName();
                break;

            case 2:
                searchByRegNo();
                break;

            case 3:
                return;

            default:
                printf("\nInvalid choice!\n");
        }
    }
}




/*search by reg no*/
void searchByRegNo(void)
{
    char reg_no[20];
    int i;
    int found = 0;

    printf("\nEnter Registration Number: ");
    scanf("%19s", reg_no);

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].reg_no, reg_no) == 0)
        {
            printf("\n");
            printf("+----------------+----------------------+-----+----------------+--------+\n");
            printf("| Reg No         | Name                 | Age | Department     | Marks  |\n");
            printf("+----------------+----------------------+-----+----------------+--------+\n");

            printf("| %-14s | %-20s | %-3d | %-14s | %-6.2f |\n",
                   students[i].reg_no,
                   students[i].name,
                   students[i].age,
                   students[i].department,
                   students[i].marks);

            printf("+----------------+----------------------+-----+----------------+--------+\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}

/*seach by name*/
void searchByName(void)
{
    char name[50];
    int i;
    int found = 0;

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", name);

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            if (!found)
            {
                printf("\n");
                printf("+----------------+----------------------+-----+----------------+--------+\n");
                printf("| Reg No         | Name                 | Age | Department     | Marks  |\n");
                printf("+----------------+----------------------+-----+----------------+--------+\n");
            }

            printf("| %-14s | %-20s | %-3d | %-14s | %-6.2f |\n",
                   students[i].reg_no,
                   students[i].name,
                   students[i].age,
                   students[i].department,
                   students[i].marks);

            found = 1;
        }
    }

    if (found)
    {
        printf("+----------------+----------------------+-----+----------------+--------+\n");
    }
    else
    {
        printf("\nStudent not found!\n");
    }
}


void updateStudent(void)
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("====================================\n");
        printf("          UPDATE STUDENT\n");
        printf("====================================\n");
        printf("1. Update by Name\n");
        printf("2. Update by Registration Number\n");
        printf("3. Back\n");
        printf("====================================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                updateByName();
                break;

            case 2:
                updateByRegNo();
                break;

            case 3:
                return;

            default:
                printf("\nInvalid choice!\n");
        }
    }
}


void updateByRegNo(void)
{
    char reg_no[20];
    int i;
    int found = 0;
    int choice;

    printf("\nEnter Registration Number: ");
    scanf("%19s", reg_no);

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].reg_no, reg_no) == 0)
        {
            found = 1;

            printf("\nStudent Found!\n");
            printf("Name       : %s\n", students[i].name);
            printf("Age        : %d\n", students[i].age);
            printf("Department : %s\n", students[i].department);
            printf("Marks      : %.2f\n", students[i].marks);

            printf("\n========== UPDATE ==========\n");
            printf("1. Name\n");
            printf("2. Age\n");
            printf("3. Department\n");
            printf("4. Marks\n");
            printf("5. Update All\n");
            printf("6. Cancel\n");

            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter new name: ");
                    scanf(" %[^\n]", students[i].name);
                    break;

                case 2:
                    printf("Enter new age: ");
                    scanf("%d", &students[i].age);
                    break;

                case 3:
                    printf("Enter new department: ");
                    scanf(" %[^\n]", students[i].department);
                    break;

                case 4:
                    printf("Enter new marks: ");
                    scanf("%f", &students[i].marks);
                    break;

                case 5:
                    printf("Enter new name: ");
                    scanf(" %[^\n]", students[i].name);

                    printf("Enter new age: ");
                    scanf("%d", &students[i].age);

                    printf("Enter new department: ");
                    scanf(" %[^\n]", students[i].department);

                    printf("Enter new marks: ");
                    scanf("%f", &students[i].marks);
                    break;

                case 6:
                    printf("Update cancelled.\n");
                    return;

                default:
                    printf("Invalid choice!\n");
                    return;
            }

            printf("\nStudent updated successfully!\n");
            return;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}



void updateByName(void)
{
    char name[50];
    int i;
    int found = 0;
    int matchCount = 0;
    int selected;

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", name);

    printf("\nMatching Students:\n");

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            printf("%d. %s | %s | Age: %d | %s | Marks: %.2f\n",
                   matchCount + 1,
                   students[i].reg_no,
                   students[i].name,
                   students[i].age,
                   students[i].department,
                   students[i].marks);

            found = 1;
            matchCount++;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
        return;
    }

    if (matchCount == 1)
    {
        for (i = 0; i < count; i++)
        {
            if (strcmp(students[i].name, name) == 0)
            {
                updateRecord(i);
                return;
            }
        }
    }

    printf("\nMultiple students found.\n");
    printf("Enter student number to update: ");
    scanf("%d", &selected);

    if (selected < 1 || selected > matchCount)
    {
        printf("Invalid selection!\n");
        return;
    }

    matchCount = 0;

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            matchCount++;

            if (matchCount == selected)
            {
                updateRecord(i);
                return;
            }
        }
    }
}


void updateRecord(int index)
{
    int choice;

    printf("\n");
    printf("====================================\n");
    printf("         UPDATE RECORD\n");
    printf("====================================\n");

    printf("Reg No      : %s\n", students[index].reg_no);
    printf("Name        : %s\n", students[index].name);
    printf("Age         : %d\n", students[index].age);
    printf("Department  : %s\n", students[index].department);
    printf("Marks       : %.2f\n", students[index].marks);

    printf("\n1. Name\n");
    printf("2. Age\n");
    printf("3. Department\n");
    printf("4. Marks\n");
    printf("5. Update All\n");
    printf("6. Cancel\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter new name: ");
            scanf(" %[^\n]", students[index].name);
            break;

        case 2:
            printf("Enter new age: ");
            scanf("%d", &students[index].age);
            break;

        case 3:
            printf("Enter new department: ");
            scanf(" %[^\n]", students[index].department);
            break;

        case 4:
            printf("Enter new marks: ");
            scanf("%f", &students[index].marks);
            break;

        case 5:
            printf("Enter new name: ");
            scanf(" %[^\n]", students[index].name);

            printf("Enter new age: ");
            scanf("%d", &students[index].age);

            printf("Enter new department: ");
            scanf(" %[^\n]", students[index].department);

            printf("Enter new marks: ");
            scanf("%f", &students[index].marks);
            break;

        case 6:
            printf("Update cancelled.\n");
            return;

        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("\nStudent updated successfully!\n");
}


void deleteStudent(void)
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("====================================\n");
        printf("          DELETE STUDENT\n");
        printf("====================================\n");
        printf("1. Delete by Name\n");
        printf("2. Delete by Registration Number\n");
        printf("3. Back\n");
        printf("====================================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                deleteByName();
                break;

            case 2:
                deleteByRegNo();
                break;

            case 3:
                return;

            default:
                printf("\nInvalid choice!\n");
        }
    }
}


void deleteByRegNo(void)
{
    char reg_no[20];
    int i;

    printf("\nEnter Registration Number: ");
    scanf("%19s", reg_no);

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].reg_no, reg_no) == 0)
        {
            deleteRecord(i);
            return;
        }
    }

    printf("\nStudent not found!\n");
}


void deleteByName(void)
{
    char name[50];
    int i;
    int found = 0;
    int matchCount = 0;
    int selected;

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", name);

    printf("\nMatching Students:\n");

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            printf("%d. %s | %s | Age: %d | %s | Marks: %.2f\n",
                   matchCount + 1,
                   students[i].reg_no,
                   students[i].name,
                   students[i].age,
                   students[i].department,
                   students[i].marks);

            found = 1;
            matchCount++;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
        return;
    }

    if (matchCount == 1)
    {
        for (i = 0; i < count; i++)
        {
            if (strcmp(students[i].name, name) == 0)
            {
                deleteRecord(i);
                return;
            }
        }
    }

    printf("\nMultiple students found.\n");
    printf("Enter student number to delete: ");
    scanf("%d", &selected);

    if (selected < 1 || selected > matchCount)
    {
        printf("Invalid selection!\n");
        return;
    }

    matchCount = 0;

    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            matchCount++;

            if (matchCount == selected)
            {
                deleteRecord(i);
                return;
            }
        }
    }
}


void deleteRecord(int index)
{
    char confirm;

    printf("\nStudent selected:\n");
    printf("Reg No      : %s\n", students[index].reg_no);
    printf("Name        : %s\n", students[index].name);
    printf("Age         : %d\n", students[index].age);
    printf("Department  : %s\n", students[index].department);
    printf("Marks       : %.2f\n", students[index].marks);

    printf("\nAre you sure you want to delete this student? (Y/N): ");
    scanf(" %c", &confirm);

    if (confirm != 'Y' && confirm != 'y')
    {
        printf("Deletion cancelled.\n");
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        students[i] = students[i + 1];
    }

    count--;

    printf("\nStudent deleted successfully!\n");
}


void sortStudents(void)
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("====================================\n");
        printf("           SORT STUDENTS\n");
        printf("====================================\n");
        printf("1. Sort by Name\n");
        printf("2. Sort by Marks\n");
        printf("3. Sort by Registration Number\n");
        printf("4. Back\n");
        printf("====================================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                sortByName();
                break;

            case 2:
                sortByMarks();
                break;

            case 3:
                sortByRegNo();
                break;

            case 4:
                return;

            default:
                printf("\nInvalid choice!\n");
        }
    }
}

void sortByName(void)
{
    int i, j;
    struct Student temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(students[i].name, students[j].name) > 0)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\nStudents sorted by Name (A-Z).\n");
}


void sortByMarks(void)
{
    int i, j;
    struct Student temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (students[i].marks < students[j].marks)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\nStudents sorted by Marks (High-Low).\n");
}



void sortByRegNo(void)
{
    int i, j;
    struct Student temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(students[i].reg_no, students[j].reg_no) > 0)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\nStudents sorted by Registration Number.\n");
}


