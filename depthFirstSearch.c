#include <stdio.h>
#define MAX_SIZE 20 
int visited[MAX_SIZE];   
int adj[MAX_SIZE][MAX_SIZE];      
int n;         
void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}
int main() {
    int edges, u, v;
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
    dfs(0);
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }
    if (connected)
        printf("The graph is CONNECTED.\n");
    else
        printf("The graph is NOT CONNECTED.\n");
    return 0;
}