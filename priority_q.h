#ifndef PQUEUE_H
#define PQUEUE_H

typedef struct Node{
    int x;
    int y;
    int dist;
}Node;

void enPqueue(Node a);
Node dePqueue();
int isPQEmpty();
void resetPQueue();

#endif