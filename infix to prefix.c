#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return -1;
}

void infixToPostfix(char infix[], char postfix[]) {
    char x;
    int i = 0, k = 0;
    while (infix[i] != '\0') {
        char token = infix[i];
        if (isalnum(token)) {
            postfix[k++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while ((x = pop()) != '(') {
                postfix[k++] = x;
            }
        } else {
            while (precedence(stack[top]) >= precedence(token)) {
                postfix[k++] = pop();
            }
            push(token);
        }
        i++;
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int evalStack[MAX];
int evalTop = -1;

void evalPush(int x) {
    evalStack[++evalTop] = x;
}

int evalPop() {
    return evalStack[evalTop--];
}

int evaluatePostfix(char postfix[]) {
    int i = 0, val;
    while (postfix[i] != '\0') {
        char token = postfix[i];
        if (isdigit(token)) {
            evalPush(token - '0');
        } else {
            int b = evalPop();
            int a = evalPop();
            switch (token) {
                case '+': val = a + b; break;
                case '-': val = a - b; break;
                case '*': val = a * b; break;
                case '/': val = a / b; break;
                case '^': val = 1;
                          for (int j = 0; j < b; j++) val *= a;
                          break;
            }
            evalPush(val);
        }
        i++;
    }
    return evalPop();
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
