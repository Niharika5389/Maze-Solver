#include<stdio.h>
#include<stdlib.h>
#include <time.h>

# define MAX 10000

typedef struct Node{
    int x;
    int y;
    int dist;
}Node;

Node Pqueue[MAX];

int Pfront = 0;
int Prear = -1;

void resetPQueue(){
    Pfront = 0;
    Prear = -1;
}

int isPQEmpty(){
    return Pfront>Prear;
}

Node dePqueue(){
    if(isPQEmpty()){
        printf("Queue empty\n");
        exit(1);
    }
    return Pqueue[Pfront++];
}
void enPqueue(Node a){
    if(Prear==MAX-1){
        printf("queue full");
        return;
    }
    int min = Prear+1;
    for(int i=0;i<=Prear;i++){
        if(a.dist<Pqueue[i].dist){
            min = i;
            break;
        }
    }
    for(int j=Prear; j>=min;j--){
        Pqueue[j+1] = Pqueue[j];
    }
    Pqueue[min] = a;
    Prear++;
    
}

