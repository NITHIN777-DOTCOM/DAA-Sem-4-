        #include <iostream>
        #include <vector>
        #include <climits>
        using namespace std;

        bool dfs(vector<vector<int>>& rGraph, int u, int t, vector<bool>& visited, vector<int>& parent, int V)
        {
            visited[u] = true;

            if(u == t)
                return true;

            for(int v=0; v<V; v++)
            {
                if(!visited[v] && rGraph[u][v] > 0)
                {
                    parent[v] = u;
                    if(dfs(rGraph,v,t,visited,parent,V))
                        return true;
                }
            }

            return false;
        }

        int fordFulkerson(vector<vector<int>>& graph, int s, int t, int V)
        {
            vector<vector<int>> rGraph = graph;
            vector<int> parent(V);
            int max_flow = 0;

            while(true)
            {
                vector<bool> visited(V,false);

                if(!dfs(rGraph,s,t,visited,parent,V))
                    break;

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

            cout<<"Enter number of vertices: ";
            cin>>V;

            vector<vector<int>> graph(V, vector<int>(V));

            cout<<"Enter capacity matrix:\n";

            for(int i=0;i<V;i++)
                for(int j=0;j<V;j++)
                    cin>>graph[i][j];

            int s,t;

            cout<<"Enter source vertex: ";
            cin>>s;

            cout<<"Enter sink vertex: ";
            cin>>t;

            int maxFlow = fordFulkerson(graph,s,t,V);

            cout<<"Maximum Flow = "<<maxFlow<<endl;

            return 0;
        }