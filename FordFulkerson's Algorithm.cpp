//Ford-Fulkerson Algorithm

/*
    6
    10
    0 1 16
    0 2 13
    1 2 10
    1 3 12
    2 1 4
    2 4 14
    3 2 9
    3 5 20
    4 3 7
    4 5 4
    0
    5
*/

#include <bits/stdc++.h>
using namespace std;
class FordFulkerson
{
public:
    int V;
    vector<vector<int>> residue;
    vector<bool> visited;
    FordFulkerson(int vertices)
    {
        V = vertices;
        residue.resize(V, vector<int>(V, 0));
        visited.resize(V);
    }
    void addEdge(int u, int v, int cap)
    {
        residue[u][v] += cap;
    }
    bool dfs(int u, int sink, vector<int>& parent)
    {
        visited[u] = true;

        if (u == sink)
            return true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && residue[u][v] > 0)
            {
                parent[v] = u;

                if (dfs(v, sink, parent))
                    return true;
            }
        }

        return false;
    }

    int maxFlow(int source, int sink)
    {
        int maxFlow = 0;

        while (true)
        {
            visited.assign(V, false);

            vector<int> parent(V, -1);

            // Find an augmenting path
            if (!dfs(source, sink, parent))
                break;

            // Find bottleneck capacity
            int pathFlow = INT_MAX;

            int v = sink;

            while (v != source)
            {
                int u = parent[v];

                pathFlow = min(pathFlow, residue[u][v]);

                v = u;
            }

            // Update residual graph
            v = sink;

            while (v != source)
            {
                int u = parent[v];

                residue[u][v] -= pathFlow;
                residue[v][u] += pathFlow;

                v = u;
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }
};

int main()
{
    int V, E;

    cin >> V >> E;

    FordFulkerson graph(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, capacity;

        cin >> u >> v >> capacity;

        graph.addEdge(u, v, capacity);
    }

    int source, sink;

    cin >> source >> sink;

    cout << "Max Flow = " << graph.maxFlow(source, sink) << endl;

    return 0;
}
