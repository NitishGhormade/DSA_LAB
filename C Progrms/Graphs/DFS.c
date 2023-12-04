#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
bool adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int vertices;

void dfs(int vertex)
{
    int i;
    visited[vertex] = true;
    printf("%d ", vertex);

    for (i = 0; i < vertices; i++)
    {
        if (adjacency_matrix[vertex][i] && !visited[i])
        {
            dfs(i);
        }
    }
}
void main()
{
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    printf("DFS: ");
    dfs(0);
    printf("\n");
}
