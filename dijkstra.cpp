#include<iostream>
#include<vector>
#include<limits>
#include <queue>

using namespace std;

void dijkstra(int V,int start, vector<vector<pair<int,int>>> graph){
    vector<int> dist(V,numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;

   pq.push({0,start});

while (!pq.empty())
   {
    int d = pq.top().first;
    int u =  pq.top().second;
    pq.pop();

    if( d > dist[u]) continue;

    for(auto [v,w] : graph[u]){
        if (dist[u]+w < dist[v]){
            dist[v] = dist[u]+w;
            pq.push({dist[v],v});
        }
    }

   }

   cout << "Vertex\tDistance from Source " << start << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == numeric_limits<int>::max())
            cout << i << "\tINF" << endl;
        else
            cout << i << "\t" << dist[i] << endl;
    }
}
   


int main(){
     int V = 6;
    vector<vector<pair<int,int>>> graph(V);

    auto addEdge = [&](int u, int v, int w){
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 2);
    addEdge(1, 2, 5);
    addEdge(1, 3, 10);
    addEdge(2, 4, 3);
    addEdge(4, 3, 4);
    addEdge(3, 5, 11);

    int start = 0;
    dijkstra(V, start, graph);
}