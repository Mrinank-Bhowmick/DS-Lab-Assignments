#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int rollNo;
    char name[100];
    struct Date dob;
    float marks;
};

void addStudent(struct Student *students, int *numStudents) {
    printf("\nEnter details of the student:\n");
    printf("Roll No: ");
    scanf("%d", &students[*numStudents].rollNo);
    printf("Name: ");
    scanf(" %[^\n]", students[*numStudents].name);
    printf("Date of Birth (dd mm yyyy): ");
    scanf("%d %d %d", &students[*numStudents].dob.day, &students[*numStudents].dob.month, &students[*numStudents].dob.year);
    printf("Marks: ");
    scanf("%f", &students[*numStudents].marks);
    (*numStudents)++;
    printf("Student added successfully.\n");
}

void displayStudents(struct Student *students, int numStudents) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Date of Birth: %02d/%02d/%d\n", students[i].dob.day, students[i].dob.month, students[i].dob.year);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    struct Student students[100]; // Assuming a maximum of 100 students
    int numStudents = 0;
    int choice;

    printf("Student Database Management System\n");
    do {
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
