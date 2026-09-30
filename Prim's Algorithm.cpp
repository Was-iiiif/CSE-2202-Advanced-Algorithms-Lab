//Prim's Algorithm
#include<iostream>
using namespace std;
#define INF 9999
#define V 5
void Prims(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool visited[V];
    for(int i=0; i<V; i++)
    {
        key[i]=INF;
        visited[i]=false;
    }
    parent[0]=-1;
    key[0]=0;
    for(int count=0; count<V-1; count++)
    {
        int u;
        int min=INF;
        for(int i=0; i<V; i++)
        {
            if(!visited[i] && key[i]<min)
            {
                min=key[i];
                u=i;
            }
        }
        visited[u]=true;
        for(int v=0; v<V; v++)
        {
            if(graph[u][v]!=0 && !visited[v] && key[v]>graph[u][v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    int totalWeight;
    cout<<"Edge"<<"\t"<<"Weight"<<endl;
    for(int i=1; i<V; i++)
    {
        cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<endl;
        totalWeight+=graph[i][parent[i]];
    }
}
int main()
{
    int graph [V][V];
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cin>>graph[i][j];
        }
    }
    Prims(graph);
}
    /*
        0 2 0 6 0
        2 0 3 8 5
        0 3 0 0 7
        6 8 0 0 9
        0 5 7 9 0
    */
