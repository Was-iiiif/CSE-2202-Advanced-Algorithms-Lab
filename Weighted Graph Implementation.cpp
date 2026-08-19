#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>>adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
void printGraph(vector<pair<int, int>>adj[], int V)
{
    int v,w;
    for(int u=0; u<V; u++)
    {
        cout<<"Node "<<u<<" makes an edge with: \n";
        for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            v=it->first;
            w=it->second;
            cout<<"Node "<<v<<" with weight "<<w<<endl;
        }
        cout<<"\n";
    }
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>>adj[V];
    for(int i=0; i<E; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(adj,u,v,wt);
    }
    printGraph(adj,V);
}
