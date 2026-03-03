#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent, int V)
{
    vector<bool> visited(V,false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v=0; v<V; v++)
        {
            if(!visited[v] && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t, int V)
{
    vector<vector<int>> rGraph = graph;
    vector<int> parent(V);

    int max_flow = 0;

    while(bfs(rGraph,s,t,parent,V))
    {
        int path_flow = INT_MAX;

        for(int v=t; v!=s; v=parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow,rGraph[u][v]);
        }

        for(int v=t; v!=s; v=parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "\nEnter the capacity matrix:\n";

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin >> graph[i][j];
        }
    }

    int s,t;

    cout << "\nEnter source vertex: ";
    cin >> s;

    cout << "Enter sink vertex: ";
    cin >> t;

    int maxFlow = fordFulkerson(graph,s,t,V);

    cout << "\nMaximum Flow = " << maxFlow << endl;

    return 0;
}