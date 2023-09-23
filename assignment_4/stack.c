#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int value) {
    stack[++(*top)] = value;
}

char pop(int *stack, int *top) {
    return stack[(*top)--];
}

int main(){
    // input : EAS*Y*QUE***ST***IO*N***
    printf("Enter your input: \n");
    char input[100];
    gets(input);
        
    int stack[100];
    int top = -1;
    for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] == '*') {
            printf("%c", pop(stack, &top));
        } else {
            push(stack, &top, input[i]);
        }
    }
    printf("\n");

}