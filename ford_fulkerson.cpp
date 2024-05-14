#include <climits>
#include <iostream>
using namespace std;
bool bfs(int** residual, int s, int t, int* parent, int N) {
    bool* visited = (bool*)malloc(N * sizeof(bool));
    for (int i = 0; i < N; ++i)
        visited[i] = false;
    int* queue = (int*)malloc(N * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[s]    = true;
    parent[s]     = -1;
    while (front != rear) {
        int u = queue[front++];
        for (int v = 0; v < N; ++v) {
            if (residual[u][v] > 0 && !visited[v]) {
                parent[v]     = u;
                visited[v]    = true;
                queue[rear++] = v;
                if (v == t) {
                    free(visited);
                    free(queue);
                    return true;
                }
            }
        }
    }
    free(visited);
    free(queue);
    return false;
}
int fordFulkerson(int** adj, int s, int t, int N) {
    int** residual = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i) {
        residual[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; ++j) {
            residual[i][j] = adj[i][j];
        }
    }
    int* parent = (int*)malloc(N * sizeof(int));
    int maxFlow = 0;
    while (bfs(residual, s, t, parent, N)) {
        int minCapacity = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u       = parent[v];
            minCapacity = min(minCapacity, residual[u][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= minCapacity;
            residual[v][u] += minCapacity;
        }
        maxFlow += minCapacity;
    }
    for (int i = 0; i < N; ++i) {
        free(residual[i]);
    }
    free(residual);
    free(parent);
    return maxFlow;
}
int main() {
    int N;  // Number of nodes
    cout << "Enter the number of nodes: ";
    cin >> N;
    int** adj = (int**)malloc(N * sizeof(int*));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < N; ++i) {
        adj[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
        }
    }
    int source, sink;  // Source and sink nodes
    cout << "Enter the source node: ";
    cin >> source;
    cout << "Enter the sink node: ";
    cin >> sink;
    int maxFlow = fordFulkerson(adj, source, sink, N);
    cout << "Maximum flow possible from source to sink: " << maxFlow << endl;
    for (int i = 0; i < N; ++i) {
        free(adj[i]);
    }
    free(adj);
    return 0;
}