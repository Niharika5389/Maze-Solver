#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node{
    int x;
    int y;
}Node;

void enqueue(Node a);
Node dequeue();
int isQEmpty();
void resetQueue();

#endif