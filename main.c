#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float grade;
};

void addStudent(FILE *fp) {
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Grade: ");
    scanf("%f", &s.grade);
    fwrite(&s, sizeof(s), 1, fp);
    printf("Student added.\n");
}

void viewStudents(FILE *fp) {
    struct Student s;
    rewind(fp);
    printf("ID\tName\tGrade\n");
    while(fread(&s, sizeof(s), 1, fp)) {
        printf("%d\t%s\t%.2f\n", s.id, s.name, s.grade);
    }
}

int main() {
    FILE *fp = fopen("students.dat", "ab+");
    if (!fp) {
        printf("Could not open file.\n");
        return 1;
    }

    int choice;
    do {
        printf("\n1. Add Student\n2. View Students\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addStudent(fp); break;
            case 2: viewStudents(fp); break;
        }
    } while(choice != 0);

    fclose(fp);
    return 0;
}
