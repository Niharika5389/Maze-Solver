#ifndef STACK_H
#define STACK_H

typedef struct Node{
    int x;
    int y;
}Node;

void push(Node a);
Node pop();
int isSEmpty();
void resetStack();

#endif