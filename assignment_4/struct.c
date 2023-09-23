#include <stdio.h>
#include <stdlib.h>
#define max_size 100

struct Stack {
    char items[max_size];
    int top;
};


void push(struct Stack *s, int value) {
    if (s->top == max_size - 1) {
        printf("Stack overflow\n");
    }
    s->items[++s->top] = value;
}

char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
    }
    return s->items[s->top--];
}

int main(){
    // input : EAS*Y*QUE***ST***IO*N***
    printf("Enter your input: \n");
    char input[max_size];
    gets(input);
    
    struct Stack stack;
    stack.top=-1;

    for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] == '*') {
            printf("%c", pop(&stack));
        } else {
            push(&stack, input[i]);
        }
    }
    printf("\n");

    return 0;
}
