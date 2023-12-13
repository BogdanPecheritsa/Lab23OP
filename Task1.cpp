#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_STUDENTS 100

typedef struct {
    char surname[100];
    char name[100];
    char patronymic[100];
    char gender[20];
    char nationality[100];
    int birth_year;
    int birth_month;
    int birth_day;
    char phone_number[20];
    char address[300];
    char university[100];
    int course;
    char group[20];
    float average_score;
    char specialty[100];
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void create_student() {
    Student new_student;
    printf("\n������ ������� ��������: ");
    scanf_s("%s", new_student.surname, (unsigned)_countof(new_student.surname)); getchar();
    printf("\n������ ��'� ��������: ");
    scanf_s("%s", new_student.name, (unsigned)_countof(new_student.name)); getchar();
    printf("\n������ �� ������� ��������: ");
    scanf_s("%s", new_student.patronymic, (unsigned)_countof(new_student.patronymic)); getchar();
    printf("\n������ ����� ��������: ");
    scanf_s("%s", new_student.gender, (unsigned)_countof(new_student.gender)); getchar();
    printf("\n������ ������������� ��������: ");
    scanf_s("%s", new_student.nationality, (unsigned)_countof(new_student.nationality)); getchar();
    printf("\n������ �� ���������� ��������: ");
    scanf_s("%d", &new_student.birth_year); getchar();
    printf("\n������ ����� ���������� ��������: ");
    scanf_s("%d", &new_student.birth_month); getchar();
    printf("\n������ ���� ���������� ��������: ");
    scanf_s("%d", &new_student.birth_day); getchar();
    printf("\n������ ����� �������� ��������: ");
    scanf_s("%s", new_student.phone_number, (unsigned)_countof(new_student.phone_number)); getchar();
    printf("\n������ ������� ������ ��������: ");
    fgets(new_student.address, sizeof(new_student.address), stdin);
    printf("\n������ ��� ��������: ");
    fgets(new_student.university, sizeof(new_student.university), stdin);
    printf("\n������ ���� ��������: ");
    scanf_s("%d", &new_student.course); getchar();
    printf("\n������ ����� ��������: ");
    scanf_s("%s", new_student.group, (unsigned)_countof(new_student.group)); getchar();
    printf("\n������ ������� ��� ��������: ");
    scanf_s("%f", &new_student.average_score); getchar();
    printf("\n������ ������������ ��������: ");
    fgets(new_student.specialty, sizeof(new_student.specialty), stdin);
    students[student_count++] = new_student;
}

void display_students() {
    printf("\n³���������� ��������:\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s %s %s %s %s %d %d %d %s %s %s %d %s %f %s\n", students[i].surname, students[i].name, students[i].patronymic, students[i].gender, students[i].nationality, students[i].birth_year, students[i].birth_month, students[i].birth_day, students[i].phone_number, students[i].address, students[i].university, students[i].course, students[i].group, students[i].average_score, students[i].specialty);
    }
}

void search_student(char* surname) {
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].surname, surname) == 0) {
            printf("%s %s %s %s %s %d %d %d %s %s %s %d %s %f %s\n", students[i].surname, students[i].name, students[i].patronymic, students[i].gender, students[i].nationality, students[i].birth_year, students[i].birth_month, students[i].birth_day, students[i].phone_number, students[i].address, students[i].university, students[i].course, students[i].group, students[i].average_score, students[i].specialty);
            return;
        }
    }
    printf("\n�������� �� ��������.\n");
}

void delete_student(char* surname) {
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].surname, surname) == 0) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("\n�������� ��������.\n");
            return;
        }
    }
    printf("\n�������� �� ��������.\n");
}

void sort_students() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (strcmp(students[j].surname, students[j + 1].surname) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    char surname[50];

    while (1) {
        printf("\n1. �������� ����� �����\n2. ������� ����� ��������\n3. ������ ����� �� ����������\n4. �������� �����\n5. ³���������� ����� ��������\n6. �����\n��� ����: ");
        scanf_s("%d", &choice); getchar();

        switch (choice) {
        case 1:
            create_student();
            break;
        case 2:
            display_students();
            break;
        case 3:
            printf("\n������ ������� ��������: ");
            scanf_s("%s", surname, (unsigned)_countof(surname)); getchar();
            search_student(surname);
            break;
        case 4:
            printf("\n������ ������� ��������: ");
            scanf_s("%s", surname, (unsigned)_countof(surname)); getchar();
            delete_student(surname);
            break;
        case 5:
            sort_students();
            display_students();
            break;
        case 6:
            exit(0);
        default:
            printf("\n������� ����\n");
            break;
        }
    }

    return 0;
}