#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex divide(Complex a, Complex b) {
    Complex result;
    float denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

void displayComplex(Complex a) {
    printf("%.2f + %.2fi\n", a.real, a.imag);
}

int main() {
    Complex a, b, result;
    int choice;

    printf("Enter the real and imaginary parts of the first complex number: \n");
    printf("Real:");
    scanf("%f", &a.real);
    printf("Imaginary:");
    scanf("%f", &a.imag);

    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = add(a, b);
            printf("Result: ");
            displayComplex(result);
            break;
        case 2:
            result = subtract(a, b);
            printf("Result: ");
            displayComplex(result);
            break;
        case 3:
            result = multiply(a, b);
            printf("Result: ");
            displayComplex(result);
            break;
        case 4:
            result = divide(a, b);
            printf("Result: ");
            displayComplex(result);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}