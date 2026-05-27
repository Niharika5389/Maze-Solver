#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include "priority_q.h"
#include "A*.h"
#include "CalcCost.h"

int a_star(int grid[100][100], int sx, int sy, int ex, int ey,int n, char grid_f[100][100]){
    FILE *fp = fopen("output.txt", "w");
    fclose(fp);

    fp = fopen("output.txt", "a");

    resetPQueue();

    Node parent[100][100];
    int dist[100][100];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = 1e9;   
        }
    }
    dist[sx][sy] = 0;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    Node start = {sx,sy,abs(sx-ex) + abs(sy-ey)};
    enPqueue(start);

    while(!isPQEmpty()){

        Node cur = dePqueue();
    
        int x = cur.x;
        int y = cur.y;

        int H = abs(x-ex) + abs(y-ey);

        if((cur.dist-H) > dist[x][y]) continue;

        printf("Visiting: (%d,%d)\n", x, y);
        fprintf(fp, "V %d %d\n", x, y);
        

        if(x==ex && y==ey){
            printf("\nShortest Path:\n");
            Node temp = {x,y};

            while(!(temp.x == sx && temp.y == sy)){
                printf("(%d,%d) <- ", temp.x, temp.y);
                grid_f[temp.x][temp.y] = '*';
                fprintf(fp, "P %d %d\n", temp.x, temp.y);
                temp = parent[temp.x][temp.y];
                
            }
            grid_f[n-1][n-1] = 'E';
            printf("(%d,%d)\n", sx, sy);
            return dist[x][y];
        }

        for(int u=0; u<4; u++){

            int nx = x + dx[u];
            int ny = y + dy[u];

            if(nx>=0 && ny>=0 && nx<n && ny<n){
                int h = abs(nx-ex) + abs(ny-ey);
                
                if(grid[nx][ny]!=1){
                    int newDist = dist[x][y] + cost(grid[nx][ny],n);
                    
                    if(newDist<dist[nx][ny]){
                        parent[nx][ny] = cur;
                        
                        dist[nx][ny] = newDist ;
                        Node c = {nx,ny,newDist+h};
                        enPqueue(c);
                    }
                    

                    
                }
            }
        }
    }
    fclose(fp);

    return -1;
}

