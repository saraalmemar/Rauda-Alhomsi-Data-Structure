#include <stdio.h>
#include <ctype.h>

#define MAX 200

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// ^ is right-associative, others are left-associative
int isRightAssociative(char op) {
    return op == '^';
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    while (infix[i] != '\0') {
        char c = infix[i];

        // ignore spaces and newlines
        if (c == ' ' || c == '\n' || c == '\t') {
            i++;
            continue;
        }

        // if operand (digit or letter), output directly
        if (isalnum((unsigned char)c)) {
            postfix[k++] = c;
        }
        // if '(' push to stack
        else if (c == '(') {
            push(c);
        }
        // if ')' pop until '('
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            if (!isEmpty() && peek() == '(') pop(); // remove '('
        }
        // operator
        else {
            while (!isEmpty() && peek() != '(') {
                char topOp = peek();

                int p1 = precedence(topOp);
                int p2 = precedence(c);

                // For left-associative: pop while p1 >= p2
                // For right-associative (^): pop while p1 > p2
                if ((!isRightAssociative(c) && p1 >= p2) ||
                    (isRightAssociative(c) && p1 > p2)) {
                    postfix[k++] = pop();
                } else {
                    break;
                }
            }
            push(c);
        }

        i++;
    }

    
    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
