#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[100];
    char gender;
    char designation[100];
    char department[100];
    float basicPay;
    float grossPay;
};

// Function to calculate gross pay for an employee
void calculateGrossPay(struct Employee *emp) {
    float HR = 0.25 * emp->basicPay; // HR = 25% of basic pay
    float DA = 0.50 * emp->basicPay; // DA = 50% of basic pay
    emp->grossPay = emp->basicPay + HR + DA;
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        scanf("%s %c %s %s %f", employees[i].name, &employees[i].gender, employees[i].designation,
              employees[i].department, &employees[i].basicPay);

        calculateGrossPay(&employees[i]);
    }

    printf("Gross salary:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %.2f\n", employees[i].name, employees[i].grossPay);
    }

    // Free the dynamically allocated memory
    free(employees);

    return 0;
}
