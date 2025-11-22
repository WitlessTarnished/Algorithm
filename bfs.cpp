#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &adj, int start)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){

   int n = 10;
vector<vector<int>> adj(n);

adj[0] = {1, 2};
adj[1] = {0, 3, 4};
adj[2] = {0, 5, 6};
adj[3] = {1, 7};
adj[4] = {1, 7, 8};
adj[5] = {2, 8};
adj[6] = {2, 9};
adj[7] = {3, 4};
adj[8] = {4, 5, 9};
adj[9] = {6, 8};

    bfs(adj,0);

}
