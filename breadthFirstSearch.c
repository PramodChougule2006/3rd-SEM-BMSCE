#include <stdio.h>
#define MAX_SIZE 20   
int adj[MAX_SIZE][MAX_SIZE];  
int visited[MAX_SIZE];    
int queue[MAX_SIZE];     
int front = -1, rear = -1;
int n;            
void enqueue(int v) {
    if (rear == MAX_SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}
int dequeue() {
    if (front == -1 || front > rear) return -1; 
    return queue[front++];
}
void bfs(int start) {
    enqueue(start);
    visited[start] = 1;
    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v); 
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int edges, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter each edge (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   
    }
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    bfs(start);
    return 0;
}