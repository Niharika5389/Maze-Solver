#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mazeGenerator.h"

void generateMaze(int grid[100][100], int n, char grid_f[100][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            int r = rand() % 100;
            if(r<30) {
                grid[i][j] = 1;
                grid_f[i][j] = '#';
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