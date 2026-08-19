#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int>pq;
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(15);
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    priority_queue<int,vector<int>, greater<int>>pqr;
    pqr.push(10);
    pqr.push(50);
    pqr.push(20);
    pqr.push(15);
    while(!pqr.empty())
    {
        cout<<pqr.top()<<" ";
        pqr.pop();
    }
}
