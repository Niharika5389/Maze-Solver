#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"
#include "Dfs_recursive.h"

Node parent[100][100];
int visited[100][100] = {0};
int dist[100][100] = {0};

int dfs_rec(int grid[100][100], int sx, int sy, int ex, int ey, int n, char grid_f[100][100])
{
    FILE *fp = fopen("output.txt", "w");
    fclose(fp);

    fp = fopen("output.txt", "a");

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    visited[sx][sy] = 1;

    printf("Visiting: (%d,%d)\n", sx, sy);
    fprintf(fp, "V %d %d\n", sx, sy);

    if (sx == ex && sy == ey)
    {
        printf("\nDFS Path:\n");

        Node temp = {ex, ey};

        while (!(temp.x == sx && temp.y == sy))
        {
            printf("(%d,%d) <- ", temp.x, temp.y);
            grid_f[temp.x][temp.y] = '*';
            fprintf(fp, "P %d %d\n", temp.x, temp.y);
            temp = parent[temp.x][temp.y];
        }

        printf("(%d,%d)\n", sx, sy);

        grid_f[sx][sy] = 'S';
        grid_f[ex][ey] = 'E';

        return 1;
    }

    for (int u = 0; u < 4; u++)
    {
        int nx = sx + dx[u];
        int ny = sy + dy[u];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n)
        {
            if (grid[nx][ny] == 0 && !visited[nx][ny])
            {
                visited[nx][ny] = 1;

                parent[nx][ny].x = sx;
                parent[nx][ny].y = sy;

                dist[nx][ny] = dist[sx][sy] + 1;

                if (dfs_rec(grid, nx, ny, ex, ey, n, grid_f))
                    return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}