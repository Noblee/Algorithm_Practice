//
// Created by Noble on 22/02/2018.
//
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n ,m;
    int a[100]={0};
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>a[i];
    int dp[50002]={0};
    for(int i =1;i<=n;i++)
    {
        dp[i] =0x7fffff;
        for(int j=0;j<m;j++)
        {
            dp[i]=min(dp[i],i-a[j]<0?0x7fffff:dp[i-a[j]]);
        }
        dp[i]++;
        cout<<i<<" "<<dp[i]<<endl;
    }
    return 0;
}