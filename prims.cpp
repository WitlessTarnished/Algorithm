#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using Graph = vector<vector<pii>>;

void prims(int start, Graph& graph, int V){
      vector<int> visited(V,0);

      priority_queue<pii,vector<pii>,greater<pii>> pq;

      pq.push({0,start});

      int totalWeight = 0;
      
      while(!pq.empty()){
        auto [w,vertex] = pq.top();
        pq.pop();

        if(visited[vertex]) continue;
        visited[vertex]=1;
        
         totalWeight += w;

       for(auto& edge: graph[vertex]) {
        int adjNode = edge.first;
        int adjWeight = edge.second;
        
        if (!visited[adjNode]){
            pq.push({adjWeight,adjNode});
        }
       }
      }

      cout<<"The total weight is: "<<totalWeight<<endl;
}

int main(){
 int V = 7; 

 Graph graph(V);

 auto addEdge = [&](int u, int v, int w){
         graph[u].push_back({v,w});
         graph[v].push_back({u,w});
 };

addEdge(0, 1, 7);
addEdge(0, 3, 5);
addEdge(1, 2, 8);
addEdge(1, 3, 9);
addEdge(1, 4, 7);
addEdge(2, 4, 5);
addEdge(3, 4, 15);
addEdge(3, 5, 6);
addEdge(4, 5, 8);
addEdge(4, 6, 9);
addEdge(5, 6, 11);

prims(0,graph,V);

}
