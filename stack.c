#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct Node{
    int x;
    int y;
}Node;

Node stack[10000];

int top = -1;

void resetStack(){
    top=-1;
}


Node pop(){
    return stack[top--];
}
void push(Node a){
    stack[++top] = a;
}

int isSEmpty(){
    return top==-1;
}