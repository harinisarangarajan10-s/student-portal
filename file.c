#include <stdio.h>
#include <xlsxwriter.h>
#include "student.h"
#include "file.h"

void saveRecords(void)
{
    FILE *fp;
    lxw_workbook *workbook;
    lxw_worksheet *worksheet;
    int i;

    /* ---------- SAVE CSV ---------- */

    fp = fopen("students.csv", "w");

    if (fp == NULL)
    {
        printf("\nError: Unable to save CSV file!\n");
        return;
    }

    fprintf(fp, "StudentID,Name,AdmissionYear,Age,Department,Marks\n");

    for (i = 0; i < count; i++)
    {
        fprintf(fp, "%s,%s,%d,%d,%s,%.2f\n",
                students[i].reg_no,
                students[i].name,
                students[i].admission_year,
                students[i].age,
                students[i].department,
                students[i].marks);
    }

    fclose(fp);

    /* ---------- CREATE EXCEL ---------- */

    workbook = workbook_new("students.xlsx");

    if (workbook == NULL)
    {
        printf("\nError: Unable to create Excel file!\n");
        return;
    }

    worksheet = workbook_add_worksheet(workbook, "Students");

    /* Header */
    worksheet_write_string(worksheet, 0, 0, "Student ID", NULL);
    worksheet_write_string(worksheet, 0, 1, "Name", NULL);
    worksheet_write_string(worksheet, 0, 2, "Admission Year", NULL);
    worksheet_write_string(worksheet, 0, 3, "Age", NULL);
    worksheet_write_string(worksheet, 0, 4, "Department", NULL);
    worksheet_write_string(worksheet, 0, 5, "Marks", NULL);

    /* Student data */
    for (i = 0; i < count; i++)
    {
        worksheet_write_string(
            worksheet, i + 1, 0,
            students[i].reg_no, NULL);

        worksheet_write_string(
            worksheet, i + 1, 1,
            students[i].name, NULL);

        worksheet_write_number(
            worksheet, i + 1, 2,
            students[i].admission_year, NULL);

        worksheet_write_number(
            worksheet, i + 1, 3,
            students[i].age, NULL);

        worksheet_write_string(
            worksheet, i + 1, 4,
            students[i].department, NULL);

        worksheet_write_number(
            worksheet, i + 1, 5,
            students[i].marks, NULL);
    }

    /* Column widths */
    worksheet_set_column(worksheet, 0, 0, 15, NULL);
    worksheet_set_column(worksheet, 1, 1, 25, NULL);
    worksheet_set_column(worksheet, 2, 2, 18, NULL);
    worksheet_set_column(worksheet, 3, 3, 10, NULL);
    worksheet_set_column(worksheet, 4, 4, 18, NULL);
    worksheet_set_column(worksheet, 5, 5, 12, NULL);

    workbook_close(workbook);

    printf("\nRecords saved successfully!\n");
    printf("CSV   : students.csv\n");
    printf("Excel : students.xlsx\n");
}


/* ---------- LOAD CSV ---------- */

void loadRecords(void)
{
    FILE *fp;
    char header[200];

    fp = fopen("students.csv", "r");

    if (fp == NULL)
    {
        printf("\nNo previous records found. Starting fresh.\n");
        count = 0;
        return;
    }

    /* Skip CSV header */
    fgets(header, sizeof(header), fp);

    count = 0;

    while (count < MAX_STUDENTS &&
           fscanf(fp,
                  "%19[^,],%49[^,],%d,%d,%29[^,],%f\n",
                  students[count].reg_no,
                  students[count].name,
                  &students[count].admission_year,
                  &students[count].age,
                  students[count].department,
                  &students[count].marks) == 6)
    {
        count++;
    }

    fclose(fp);

    printf("\n%d student record(s) loaded successfully.\n", count);
}