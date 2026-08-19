/* Sample Input:
5
10
0 1 6
0 2 7
1 2 8
1 3 5
1 4 -4
2 3 -3
2 4 9
3 1 -2
4 3 7
4 0 2
0
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>bellmanFord(vector<vector<int>>&edges, int V, int src)
{
    vector<int>dist(V, 1000);
    dist[src]=0;
    for(int i=0; i<V; i++)
    {
        for(vector<int>edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(dist[u]!=1000 && dist[u]+w<dist[v])
            {
                if(i==V-1)
                {
                    return{-1};
                }
                dist[v]=dist[u]+w;
            }
        }
    }
    return dist;
}
int main()
{
    int V, E;
    cin>>V>>E;
    vector<vector<int>>edges;
    for(int i=0; i<E; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src;
    cin>>src;
    vector<int>ans=bellmanFord(edges, V, src);
    for(int dist:ans)
        cout<<dist<<" ";
    return 101;
}
