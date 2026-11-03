#include<bits/stdc++.h>
using namespace std;

int maxCrossingSum(int arr[], int low, int high, int mid, int &start, int &end)
{
    int leftsum=-1e8;
    int rightsum=-1e8;
    int sum=0;
    for(int i=mid; i>=low; i--)
    {
        sum+=arr[i];
        if(sum>leftsum)
        {
            leftsum=sum;
            start=i;
        }
    }
    sum=0;
    for(int i=mid+1; i<=high; i++)
    {
        sum+=arr[i];
        if(sum>rightsum)
        {
            rightsum=sum;
            end=i;
        }
    }
    return leftsum+rightsum;

}
int maxSubarraySum(int arr[], int low, int high, int &start, int &end )
{
    if(low==high)
        return arr[low];
    int mid=low+(high-low)/2;
    int leftsum, leftstart, leftend;
    int rightsum, rightstart, rightend;
    int crosssum, crossstart, crossend;
    leftsum=maxSubarraySum(arr, low, mid, leftstart, leftend);
    rightsum=maxSubarraySum(arr, mid+1, high, rightstart, rightend);
    crosssum=maxCrossingSum(arr, low, high, mid, crossstart, crossend);
    if(leftsum>=rightsum && leftsum>=crosssum)
    {
        start=leftstart;
        end=leftend;
        return leftsum;
    }

    else if(rightsum>=leftsum && rightsum>=crosssum)
    {
        start=rightstart;
        end=rightend;
        return rightsum;
    }
    else
    {
        start=crossstart;
        end=crossend;
        return crosssum;
    }

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int start, end;
    int sum=maxSubarraySum(arr, 0, n-1, start, end);
    cout<<start<<" "<<end;
    cout<<endl<<sum;
}
