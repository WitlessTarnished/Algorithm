#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

struct Edge {
    int u, v, w;
};

void dijkstra(int V, int start, const vector<Edge>& edges) {
    const int INF = numeric_limits<int>::max();
    vector<int> dist(V, INF);
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto &edge : edges) {
            if (edge.u == u) {
                int v = edge.v;
                int w = edge.w;

                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    cout << "Vertex\tDistance from Source " << start << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\tINF\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int V = 6;
    vector<Edge> edges;

    auto addEdge = [&](int u, int v, int w) {
        edges.push_back({u, v, w});
        edges.push_back({v, u, w}); // undirected graph
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 2);
    addEdge(1, 2, 5);
    addEdge(1, 3, 10);
    addEdge(2, 4, 3);
    addEdge(4, 3, 4);
    addEdge(3, 5, 11);

    int start = 0;
    dijkstra(V, start, edges);

    return 0;
}
