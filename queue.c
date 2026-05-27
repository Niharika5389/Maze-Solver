#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct Node{
    int x;
    int y;
}Node;

Node queue[100];

int front = 0;
int rear = -1;

void resetQueue(){
    front = 0;
    rear = -1;
}


Node dequeue(){
    return queue[front++];
}
void enqueue(Node a){
    queue[++rear] = a;
}

int isQEmpty(){
    return front>rear;
}