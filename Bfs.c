#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include "queue.h"
#include "Bfs.h"

int bfs(int grid[100][100], int sx, int sy, int ex, int ey,int n, char grid_f[100][100]){
    FILE *fp = fopen("output.txt", "w");
    fclose(fp);

    fp = fopen("output.txt", "a");

    resetQueue();

    Node parent[100][100];
    int visited[100][100] = {0};
    int dist[100][100] = {0};

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    Node start = {sx,sy};

    visited[sx][sy] = 1;
    enqueue(start);

    while(!isQEmpty()){

        Node cur = dequeue();

        int x = cur.x;
        int y = cur.y;

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

                if(grid[nx][ny]!=1 && !visited[nx][ny]){
                    parent[nx][ny] = cur;
                    visited[nx][ny] = 1;
                    dist[nx][ny] = dist[x][y] + 1;

                    Node c = {nx,ny};
                    enqueue(c);
                }
            }
        }
    }
    fclose(fp);
    return -1;
}

