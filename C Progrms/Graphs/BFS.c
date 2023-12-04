#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int queue[MAX_VERTICES], front = -1, rear = -1;
int vertices;

bool is_queue_empty() {
    return front == rear;
}
void enqueue(int v) {
    queue[++rear] = v;
}
int dequeue() {
    return queue[++front];
}

void bfs(int source) {
	int v;
    enqueue(source);
    visited[source] = true;

    while (!is_queue_empty()) {
        int u = dequeue();
        printf("%d ", u);

        for (v = 0; v < vertices; v++) {
            if (adjacency_matrix[u][v] == 1 && !visited[v]) {
                enqueue(v);
                visited[v] = true;
            }
        }
    }
}

void main() {
	int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the elements of adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }
    printf("BFS: ");
    bfs(0);
    printf("\n");
}

