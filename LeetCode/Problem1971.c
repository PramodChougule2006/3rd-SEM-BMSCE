typedef struct Node {
        int vertex;
        struct Node* next;
    } Node;

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    Node** adjList = (Node**)calloc(n, sizeof(Node*));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        Node* nodeV = (Node*)malloc(sizeof(Node));
        nodeV->vertex = v; nodeV->next = adjList[u];
        adjList[u] = nodeV;
        Node* nodeU = (Node*)malloc(sizeof(Node));
        nodeU->vertex = u; nodeU->next = adjList[v];
        adjList[v] = nodeU;
    }
    int* stack = (int*)malloc(n * sizeof(int));
    int top = 0;
    int* visited = (int*)calloc(n, sizeof(int));
    stack[top++] = source;
    visited[source] = 1;
    while (top > 0) {
        int node = stack[--top];
        if (node == destination) return true;
        for (Node* cur = adjList[node]; cur; cur = cur->next) {
            if (!visited[cur->vertex]) {
                visited[cur->vertex] = 1;
                stack[top++] = cur->vertex;
            }
        }
    }
    return false;
}
