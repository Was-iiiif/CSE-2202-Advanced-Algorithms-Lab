#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<vector<pair<int, int>>> generateRandomGraph(int V, int E)
{
    vector<vector<pair<int, int>>> graph(V);

    mt19937 rng(
        chrono::steady_clock::now().time_since_epoch().count()
    );

    uniform_int_distribution<int> weightDist(-5, 15);

    vector<vector<bool>> exists(V, vector<bool>(V, false));

    // Create a random ordering of vertices
    vector<int> vertices(V);

    for (int i = 0; i < V; i++)
        vertices[i] = i;

    shuffle(vertices.begin(), vertices.end(), rng);
    for (int i = 1; i < V; i++)
    {
        uniform_int_distribution<int> parentDist(0, i - 1);

        int parent = vertices[parentDist(rng)];
        int child = vertices[i];

        int weight = weightDist(rng);

        graph[parent].push_back({child, weight});
        exists[parent][child] = true;
    }

    uniform_int_distribution<int> vertexDist(0, V - 1);

    int currentEdges = V - 1;
    while (currentEdges < E)
    {
        int u = vertexDist(rng);
        int v = vertexDist(rng);

        if (u == v)
            continue;

        if (exists[u][v])
            continue;

        int weight = weightDist(rng);

        graph[u].push_back({v, weight});
        exists[u][v] = true;

        currentEdges++;
    }

    return graph;
}

void printGraph(const vector<vector<pair<int, int>>>& graph)
{
    cout << "\nGenerated Graph:\n\n";

    for (int u = 0; u < graph.size(); u++)
    {
        cout << u << " -> ";

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int wt = edge.second;

            cout << "(" << v << ", " << wt << ") ";
        }

        cout << endl;
    }
}


bool BellmanFord(int V, const vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& parent, int source)
{
    dist.assign(V, INF);
    parent.assign(V, -1);
    dist[source] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        bool updated = false;

        for (int u = 0; u < V; u++)
        {
            if (dist[u] == INF)
                continue;

            for (auto edge : adj[u])
            {
                int v = edge.first;
                int wt = edge.second;

                if (dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    parent[v] = u;

                    updated = true;
                }
            }
        }
        if (!updated)
            break;
    }

    for (int u = 0; u < V; u++)
    {
        if (dist[u] == INF)
            continue;

        for (auto edge : adj[u])
        {
            int v = edge.first;
            int wt = edge.second;

            if (dist[u] + wt < dist[v])
            {
                cout << "\nNegative Cycle Found!\n";
                return false;
            }
        }
    }

    return true;
}

void printDistances(const vector<int>& dist)
{
    cout << "\nShortest Distances:\n";

    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " -> ";
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }
}

void printPath(int source, int target, const vector<int>& parent)
{
    if (target == source)
    {
        cout << source << endl;
        return;
    }
    if (parent[target] == -1)
    {
        cout << "No Path Exists!\n";
        return;
    }
    vector<int> path;
    int current = target;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());
    cout << "Shortest Path: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}


int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph = generateRandomGraph(V, E);
    printGraph(graph);
    int source;
    cout << "\nEnter source vertex: ";
    cin >> source;
    vector<int> dist;
    vector<int> parent;
    bool success = BellmanFord( V, graph, dist, parent, source);
    if (!success)
    {
        cout << "Shortest paths cannot be determined because "
             << "a reachable negative cycle exists.\n";
        return 0;
    }
    printDistances(dist);
    int target;
    cout << "\nEnter target vertex: ";
    cin >> target;
    if (target < 0 || target >= V)
    {
        cout << "Invalid target vertex!\n";
        return 0;
    }
    printPath(source, target, parent);

    return 0;
}