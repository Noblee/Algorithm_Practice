//
// Created by Noble on 22/02/2018.
//
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N,M,dp[5005][402]={0};
    cin>>N>>M;
    int W[402]={0},V[402]={0};
    for(int i =1;i<=N;i++)
    {
        cin>>W[i]>>V[i];
    }
    for(int i = 1;i<=M;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            dp[j][i]=max(dp[j-1][i],(i-W[j])>=0?(dp[j-1][(i-W[j])]+V[j]):0);
        }
    }
    printf("%d",dp[N][M]);
    return 0;
}