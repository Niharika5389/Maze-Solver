#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ComplexMaze.h"
#include "CalcCost.h"

int cost(int x,int n){
    if(x==2){
        return 5;
    }else if(x==3){
        return 10;
    }else if(x==0){
        return 1;
    }
    return 0;  
}