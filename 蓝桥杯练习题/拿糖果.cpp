#include <bits/stdc++.h>
using namespace std;
int zhishu[1000]={0};
int dp[100000];
int main()
{
	fill(zhishu+2,zhishu+1000,1);
	for(int i=2;i<sqrt(1000);i++)
	{
		for(int j = i+i;j<1000;j+=i)
		{
			zhishu[j]=0;
		}
	}
	int N;
	cin>>N;
	for(int i =2;i<=N;i++)
	{
		int temp = (int)(floor(sqrt(i)));
		int maxnum=0;
		for(int z=temp;z>=2;z--)
		{
			if(zhishu[z]==1&&i%z==0)
			{	
				if(i-2*z>=0)
				{
				 maxnum =max(maxnum,dp[i-2*z]+z);
				}
			}
		}
		dp[i]=maxnum;		
	}
	for(int i =4;i<N;i++)
	cout<<i<<" "<<dp[i]<<endl;
	cout<<dp[N];
	return 0;
}
