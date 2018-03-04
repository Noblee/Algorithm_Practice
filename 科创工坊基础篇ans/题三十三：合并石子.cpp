/*小数据能过，大数据会超时 
#include <iostream>
using namespace std;
#define N 100
*/

/*
经典DP问题，在n数据的范围内，通过求取n-1个区部最优解来得到全局最优解，本题不适合贪心算法：
在此我们假设有n堆石子，每合并相邻两堆石子得到一个费用，求解最终合并为一堆时总费用最少。
这里定义arr[i][j]为第i堆石子到第j堆石子合并后的最少总费用，a(i)为第i堆石子的石子数量,sum(i,j)为第i堆石子到第j堆石子的总和 
当石子堆为1堆时，arr[i][i]=0;
当石子堆为2堆时，arr[i][i+1]=a(i)+a(i+1);
当石子堆为3堆时，arr[i][i+2]=MIN((arr[i][i]+arr[i+1][i+2]+sum(i,i+2)),(arr[i][i+1]+arr[i+2][i+2]+sum(i,i+2));
......
当石子堆为n堆时...... 
*/

/*int fun(int a[],int n)
{
	int i,j,k,l,min=0,sum;
	int arr[N][N]; 
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++) arr[i][j]=0;//初始化第i堆石子到第j堆石子最少费用为0
	//当只有一堆石子时，arr[i][i]=0已定义
	//当有两堆石子时,总费用即为两堆石子之和 
	for(i=1;i<=n-1;i++) 
	{
		j=i+1;
		arr[i][j]=a[i]+a[j];  
	}
	//当有三堆以上的石子时
	for(k=3;k<=n;k++)
	 for(i=1;i<=n-k+1;i++)
	 {
	 	sum=0;
		j=i+k-1;//j为距离i k-1的堆编号
		for(int m=i;m<=j;m++) sum+=a[m];
		arr[i][j]=arr[i+1][j]+sum;//这里假设a[i+1][j]+sum为	arr[i][j]最小值 
		//arr[i][j]与其它情况比较，取最小值
		for(l=i+1;l<j;l++)
		{
			int tmp=arr[i][l]+arr[l+1][j]+sum;
			if(tmp<arr[i][j]) arr[i][j]=tmp;
		} 
	 } 
	 min=arr[1][n];
	 return min;	   
}

int main()
{
    int n,i;
    int p[N];
	while(cin>>n)
	{
		for(i=1;i<=n;i++) cin>>p[i];
        cout<<fun(p,n)<<endl;	
	}	
	return 0;
}
*/

//大数据能过
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N = 50005;

int stone[N];
int n,t,ans;

void combine(int k)
{
    int tmp = stone[k] + stone[k-1];
    ans += tmp;
    for(int i=k;i<t-1;i++)
        stone[i] = stone[i+1];
    t--;
    int j = 0;
    for(j=k-1;j>0 && stone[j-1] < tmp;j--)
        stone[j] = stone[j-1];
    stone[j] = tmp;
    while(j >= 2 && stone[j] >= stone[j-2])
    {
        int d = t - j;
        combine(j-1);
        j = t - d;
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0) break;
        for(int i=0;i<n;i++)
            scanf("%d",stone+i);
        t = 1;
        ans = 0;
        for(int i=1;i<n;i++)
        {
            stone[t++] = stone[i];
            while(t >= 3 && stone[t-3] <= stone[t-1])
                combine(t-2);
        }
        while(t > 1) combine(t-1);
        printf("%d\n",ans);
    }
    return 0;
}
 
