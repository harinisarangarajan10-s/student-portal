#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

struct Student
{
    char reg_no[20];
    char name[50];
    int admission_year;
    int age;
    char department[30];
    float marks;
};

extern struct Student students[MAX_STUDENTS];
extern int count;

void addStudent(void);
void displayStudents(void);

void searchStudent(void);
void searchByName(void);
void searchByRegNo(void);

void updateStudent(void);
void updateByName(void);
void updateByRegNo(void);
void updateRecord(int index);

void deleteStudent(void);
void deleteByName(void);
void deleteByRegNo(void);
void deleteRecord(int index);

void sortStudents(void);
void sortByName(void);
void sortByMarks(void);
void sortByRegNo(void);

void generateRegNo(char reg_no[]);

#endif