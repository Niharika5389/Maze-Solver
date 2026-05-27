#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mazeGenerator.h"
#include "ComplexMaze.h"
#include "Bfs.h"
#include "Dfs.h"
#include "Dfs_recursive.h"
#include "Dijkstra.h"
#include "A*.h"

void print_Mat(int grid[100][100], int n, int m, char grid_f[100][100])
{

    printf("\nDistance: %d\n", m);

    printf("  ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < n; j++)
        {
            printf("%c ", grid_f[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    int grid[100][100];
    char grid_f[100][100];

    int n;

    printf("Maze dimensions : ");
    scanf("%d", &n);

    int c;
    printf("1.Simple Maze\n2.Complex Maze\n");
    scanf("%d", &c);
    if (c == 1)
    {
        generateMaze(grid, n, grid_f);

        printf("  ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", i);
            for (int j = 0; j < n; j++)
            {
                printf("%c ", grid_f[i][j]);
            }
            printf("\n");
        }
    }
    else if (c == 2){
        maze(grid, n, grid_f);

        printf("  ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", i);
            for (int j = 0; j < n; j++)
            {
                printf("%c ", grid_f[i][j]);
            }
            printf("\n");
        }
    }

    int k, m;
    while (1)
    {
        printf("1.Dfs\n2.Bfs\n3.Dfs recursive\n4.Dijkstra\n5.A*\n6.Exit\n");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            m = dfs(grid, 0, 0, n - 1, n - 1, n, grid_f);
            print_Mat(grid, n, m, grid_f);
            break;
        case 2:
            m = bfs(grid, 0, 0, n - 1, n - 1, n, grid_f);
            print_Mat(grid, n, m, grid_f);
            break;
        case 3:
            m = dfs_rec(grid, 0, 0, n - 1, n - 1, n, grid_f);
            print_Mat(grid, n, m, grid_f);
            break;
        case 4:
            m = dijkstra(grid, 0, 0, n - 1, n - 1, n, grid_f);
            print_Mat(grid, n, m, grid_f);
            break;
        case 5:
            m = a_star(grid, 0, 0, n - 1, n - 1, n, grid_f);
            print_Mat(grid, n, m, grid_f);
            break;
        case 6:
            exit(1);
        }
    }
}