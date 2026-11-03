#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, amount;
    cin>>n;
    vector<int>coins(n);
    for(int i=0; i<n; i++)
        cin>>coins[i];
    cin>>amount;
    vector<int>dp(amount+1, INT_MAX);
    dp[0]=0;
    for(int a=1; a<=amount; a++)
    {
        for(int i=0; i<n; i++)
        {
            if(coins[i]<=a)
                dp[a]=min(dp[a], dp[a-coins[i]]+1);
        }
    }
    cout<<dp[amount]<<endl;

}
