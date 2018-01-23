#include <iostream>
#include <cstring>
using namespace std;
int a[10002];//每个木桩的最大弹性力 
int count[10002];//表示袋鼠跳到i木桩时所需要的最小跳跃数 
bool flag[10002];//表示袋鼠是否已跳过此木桩 

int main()
{
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	memset(count,0,sizeof(count));
	memset(flag,false,sizeof(flag));
	count[1]=0;//初始化
	flag[1]=true;
	//执行的循环次数越少，flag标志位最先达到true，就表示最快需要达到对岸的最小跳跃数 
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=a[i]+i;j++)
		{
			if(flag[i] && !flag[j])
			{
				count[j]=count[i]+1;
				flag[j]=true;
			}
		}
	}
	if(flag[n+1]) cout<<count[n+1];
	else cout<<-1; 
	return 0;
}
