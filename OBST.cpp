#include<bits/stdc++.h>
using namespace std;
void printTree(vector<vector<int>>&root, vector<int>&key, int i, int j, int parent=-1)
{
    if(i>j)
        return;
    int r=root[i][j];
    if(parent==-1)
        cout<<key[r]<<"(Root)"<<endl;
    else if(r<parent)
        cout<<key[r]<<"(Left child of"<<key[parent]<<")\n";
    else
        cout<<key[r]<<"(Right child of"<<key[parent]<<")\n";
    printTree(root, key, i, r-1, r);
    printTree(root, key, r+1, j, r);
}

int countComparison(vector<vector<int>>&root, vector<int>&key, int i, int j, int target)
{
    int comp=0;
    while(i<=j)
    {
        int r=root[i][j];
        comp++;
        if(key[r]==target)
            return comp;
        else if(target<key[r])
            j=r-1;
        else
            i=r+1;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<double>p(n);
    vector<int>key(n);
    for(int i=0; i<n; i++)
        cin>>key[i];
    for(int i=0; i<n; i++)
        cin>>p[i];

    vector<vector<double>>dp(n, vector<double>(n,0));
    vector<vector<int>>root(n, vector<int>(n,0));
    vector<double>prefix(n+1);
    for(int i=0; i<n; i++)
        prefix[i+1]=prefix[i]+p[i];
    for(int i=0; i<n; i++)
    {
        dp[i][i]=p[i];
        root[i][i]=i;
    }
    for(int len=2; len<=n; len++)
    {
        for(int i=0; i<=n-len; i++)
        {
            int j=i+len-1;
            double sum=prefix[j+1]-prefix[i];
            dp[i][j]=DBL_MAX;
            for(int r=i; r<=j; r++)
            {
                double left=(r>i)?dp[i][r-1]:0;
                double right=(r<j)?dp[r+1][j]:0;
                double cost=left+right+sum;
                if(cost<dp[i][j])
                {
                    dp[i][j]=cost;
                    root[i][j]=r;
                }
            }
        }
    }
    cout<<"Min Cost: "<<dp[0][n-1]<<endl;
    printTree(root, key, 0, n-1);
    return 0;
}
