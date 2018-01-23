#include <iostream>
#include <algorithm>
#define N 100
  int min(  int x,  int y)
{
    return x<y? x:y;
}
int main()
{
    int dp[N][N]={0};
    int map[N]={0};
    freopen("data.in","r",stdin);
    int n,i,j,k;
    scanf("%d", &n);
    for(i=0;i<=n;i++)
        scanf("%d",&map[i]);

    for(j=1;j<=n-1;j++)
    {
        for(i=j-1;i>=0;i--)
        {
            for(k=i;k<=j-1;k++)
            {
                if(dp[i][j]!=0)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+map[i]*map[k+1]*map[j+1]);
                else
                    dp[i][j]=dp[i][k]+dp[k+1][j]+map[i]*map[k+1]*map[j+1];
                for(int i=0;i<n;i++,printf("\n"))
                    for(int j=0;j<n;j++)
                        printf("%5d ",dp[i][j]);
                printf("\n");
            }
        }
    }
    printf("%d",dp[0][n-1]);
    return 0;
}
