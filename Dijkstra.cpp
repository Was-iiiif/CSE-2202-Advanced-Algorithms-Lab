#include<bits/stdc++.h>
using namespace std;
void generateRandomConnectedGraph(int n, int m, vector<vector<pair<int, int>>> &adj)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> weightDist(1, 20);
    set<pair<int, int>> edges;
    for (int i = 2; i <= n; i++)
    {
        uniform_int_distribution<> parentDist(1, i - 1);
        int u = i;
        int v = parentDist(gen);
        int weight = weightDist(gen);
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
        edges.insert({min(u, v), max(u, v)});
    }
    uniform_int_distribution<> vertexDist(1, n);
    while ((int)edges.size() < m)
    {
        int u = vertexDist(gen);
        int v = vertexDist(gen);
        if (u == v)
            continue;
        int a = min(u, v);
        int b = max(u, v);
        if (edges.count({a, b}))
            continue;
        int weight = weightDist(gen);
        edges.insert({a, b});
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
}
void printGraph(vector<vector<pair<int, int>>> &adj,int n)
{
    cout << "\nRandom Connected Weighted Graph:\n\n";
    for (int u = 1; u <= n; u++)
    {
        cout << "Vertex " << u << " -> ";
        for (auto edge : adj[u])
        {
            cout << "("<< edge.first<< ", weight=" << edge.second<< ") ";
        }

        cout << endl;
    }
}
void Dijkstra(int source, vector<vector<pair<int, int>>>&adj, vector<int>&dist, vector<int>&parent, int n)
{
    dist.assign(n+1, INT16_MAX);
    parent.assign(n+1, -1);
    priority_queue<
        pair<int, int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    >pq;
    dist[source]=0;
    pq.push({0, source});
    while(!pq.empty())
    {
        int currentDist=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(currentDist>dist[u])
        continue;
        for(auto edge: adj[u])
        {
            int v= edge.first;
            int weight=edge.second;
            if(dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
                parent[v]=u;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(dist[i]==INT16_MAX)
        cout<<i<<" ->"<<" INF"<<endl;
        else
        cout<<i<<" -> "<<dist[i]<<endl;
    }
}
void pathPrint(int source, int target, vector<int>&parent)
{
    if(target==source)
    {
        cout<<source<<endl;
        return;
    }
    if(parent[target]==-1)
    {
        cout<<" No path exists"<<endl;
        return;
    }
    vector<int>path;
    int current=target;
    while(current!=-1)
    {
        path.push_back(current);
        current=parent[current];
    }
    reverse(path.begin(), path.end());
    for(auto x:path)
    cout<<x<<" ";
}
int main()
{
    int v,e;
    cout<<"Provide num of vertices and edges: "<<endl;
    cin>>v>>e;
    vector<vector<pair<int, int>>>adj(v+1);
    generateRandomConnectedGraph(v, e, adj);
    printGraph(adj, v);
    cout<<"Provide source: "<<endl;
    int source;
    cin>>source;
    vector<int>dist;
    vector<int> parent;
    cout<<"Single Source Shortest Path: "<<endl;
    Dijkstra(source, adj, dist, parent, v);
    cout<<"Provide target: "<<endl;
    int target;
    cin>>target;
    cout<<"Path from "<<source<<" to "<<target<<":"<<endl;
    pathPrint(source, target, parent);
    return 0;
}

