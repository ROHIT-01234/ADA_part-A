#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Depth-First Search (DFS) Algorithm
void dfs(int graph[][MAX_SIZE], int size, int start, bool visited[]) {
    int stack[MAX_SIZE];
    int top = -1;
    int vertex;

    stack[++top] = start;

    while (top != -1) {
        vertex = stack[top--];

        if (!visited[vertex]) {
            visited[vertex] = true;
            printf("%d ", vertex);

            for (int i = size - 1; i >= 0; i--) {
                if (graph[vertex][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}

// Breadth-First Search (BFS) Algorithm
void bfs(int graph[][MAX_SIZE], int size, int start, bool visited[]) {
    int queue[MAX_SIZE];
    int front = 0, rear = -1;
    int vertex;

    queue[++rear] = start;

    while (front <= rear) {
        vertex = queue[front++];

        if (!visited[vertex]) {
            visited[vertex] = true;
            printf("%d ", vertex);

            for (int i = 0; i < size; i++) {
                if (graph[vertex][i] && !visited[i]) {
                    queue[++rear] = i;
                }
            }
        }
    }
}

int main() {
    int graph[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    int size = 5;
    int start = 0;
    bool visited[MAX_SIZE] = {false};

    printf("DFS traversal: ");
    dfs(graph, size, start, visited);
    printf("\n");

    // Resetting visited array for BFS
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }

    printf("BFS traversal: ");
    bfs(graph, size, start, visited);
    printf("\n");

    return 0;
}
