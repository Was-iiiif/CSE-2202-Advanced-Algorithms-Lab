#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int>adj[], int V)
{
    for(int u=0; u<V; u++)
    {
        cout<<"Node "<<"makes an edge with: ";
        {
            for(int j:adj[u])
                cout<<j<<" ";
        }
           cout<<endl;
    }

}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i=0; i<E; i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    printGraph(adj,V);
}
