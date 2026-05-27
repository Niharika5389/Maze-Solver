#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ComplexMaze.h"

void maze(int grid[100][100], int n, char grid_f[100][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            int r = rand() % 100;
            if(r<20) {
                grid[i][j] = 1;
                grid_f[i][j] = '#';
            }else if(r<70){
                grid[i][j]=2;
                grid_f[i][j] = '^';
            }else if(r<90){
                grid[i][j]=3;
                grid_f[i][j] = '~';
            }else {
                grid[i][j]=0;
                grid_f[i][j] = '.';
            }
        }
    }
    grid[0][0] = 0;
    grid_f[0][0] = 'S';
    grid[n-1][n-1] = 0;
    grid_f[n-1][n-1] = 'E';
}