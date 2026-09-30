//Kruskal's Algorithm

/*
5 7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
*/
#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v, weight;
};
class DSU{
    public:
    vector<int>parent, rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
        }
    }
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int a, int b)
    {
        a=find(a);
        b=find(b);
        if(a==b)
            return false; //cycle detected
        if(rank[a]<rank[b])
            swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b])
            rank[a]++;
        return true;
    }
};
void Kruskal(int V, vector<Edge>&edges)
{
    sort(edges.begin(), edges.end(),
    [](Edge a, Edge b)
    {
        return a.weight<b.weight;
    });
    DSU dsu(V);
    int totalWeight=0;
    int count=0;
    cout<<"Edge\tWeight\n";
    for(Edge x: edges)
    {
        if(dsu.unite(x.u, x.v))
        {
            cout<<x.u<<"-"<<x.v<<"\t"<<x.weight;
            cout<<endl;
            totalWeight+=x.weight;
            count++;
            if(count==V-1)
                break;
        }
    }
    cout<<"Total Weight="<<totalWeight<<endl;

}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<Edge>edges(E);
    for(int i=0; i<E; i++)
    {
        cin>>edges[i].u>>edges[i].v>>edges[i].weight;
    }
    Kruskal(V, edges);
}
