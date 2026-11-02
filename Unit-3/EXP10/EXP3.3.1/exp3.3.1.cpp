#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
    vector<vector<int>> adj(n);    //adjacency list
    for (auto& e : edges) {    //for each edge e in edges
        adj[e[0]].push_back(e[1]);   //add e[1] to the neighbor list of e[0]
        adj[e[1]].push_back(e[0]);   //add e[0] to the neighbor list of e[1]
    }
    if (source == destination) {
        return true;
    }
//BFS:
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int next : adj[node]) {
            if (next == destination) {
                return true;
            }
            if (!visited[next]) {    //check whether seen it before
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}
int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter the edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    int source, destination;
    cout << "Enter source: ";
    cin >> source;
    cout << "Enter destination: ";
    cin >> destination;
    bool result = validPath(n, edges, source, destination);
    cout << "Output: " << (result ? "true" : "false") << endl;
    return 0;
}
