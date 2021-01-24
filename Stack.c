//
// Created by ericd on 24/01/2021.
//
#define MAX 20
#include "Stack.h"
#include <stdio.h>
//creates a new empty stack
int currentIndex = 0;
int Stack[MAX];

int* init_stack() {
    for(int i = 0; i <= MAX; i++) {     // fills array with nulls
        Stack[i] = '\0';
    }
    return Stack;
}

int* push(int num) {
    currentIndex++;
    Stack[currentIndex] = num;

    return Stack;
}

int* pop() {
    Stack[currentIndex] = '\0';
    currentIndex--;

    return Stack;
}

void top() {
    printf("%d", Stack[currentIndex]);
}
