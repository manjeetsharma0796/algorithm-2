#include <iostream>
#include <stack>
#include <vector>
using namespace std;
enum Color { WHITE,
             GRAY,
             BLACK };
vector<Color> color;
vector<bool> cycle;
vector<vector<int>> adj;
stack<int> topologicalOrder;
bool topologicalSortUtil(int u) {
    color[u] = GRAY;
    for (int v : adj[u]) {
        if (color[v] == WHITE) {
            if (topologicalSortUtil(v))
                return cycle[u] = true;
        } else if (color[v] == GRAY) {
            return cycle[u] = true;
        }
    }
    color[u] = BLACK;
    topologicalOrder.push(u);
    return false;
}
void topologicalSort(int V) {
    color.assign(V, WHITE);
    cycle.assign(V, false);
    for (int u = 0; u < V; u++) {
        if (color[u] == WHITE) {
            if (topologicalSortUtil(u))
                cout << "Cycle detected!" << endl;
        }
    }
    cout << "Topological Order: ";
    while (!topologicalOrder.empty()) {
        cout << topologicalOrder.top() << " ";
        topologicalOrder.pop();
    }
    cout << endl;
}
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    adj.resize(V);
    cout << "Enter the edges (u, v) in the graph:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topologicalSort(V);
    return 0;
}