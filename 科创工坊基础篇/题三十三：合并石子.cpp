/*С�����ܹ��������ݻᳬʱ 
#include <iostream>
using namespace std;
#define N 100
*/

/*
����DP���⣬��n���ݵķ�Χ�ڣ�ͨ����ȡn-1���������Ž����õ�ȫ�����Ž⣬���ⲻ�ʺ�̰���㷨��
�ڴ����Ǽ�����n��ʯ�ӣ�ÿ�ϲ���������ʯ�ӵõ�һ�����ã�������պϲ�Ϊһ��ʱ�ܷ������١�
���ﶨ��arr[i][j]Ϊ��i��ʯ�ӵ���j��ʯ�Ӻϲ���������ܷ��ã�a(i)Ϊ��i��ʯ�ӵ�ʯ������,sum(i,j)Ϊ��i��ʯ�ӵ���j��ʯ�ӵ��ܺ� 
��ʯ�Ӷ�Ϊ1��ʱ��arr[i][i]=0;
��ʯ�Ӷ�Ϊ2��ʱ��arr[i][i+1]=a(i)+a(i+1);
��ʯ�Ӷ�Ϊ3��ʱ��arr[i][i+2]=MIN((arr[i][i]+arr[i+1][i+2]+sum(i,i+2)),(arr[i][i+1]+arr[i+2][i+2]+sum(i,i+2));
......
��ʯ�Ӷ�Ϊn��ʱ...... 
*/

/*int fun(int a[],int n)
{
	int i,j,k,l,min=0,sum;
	int arr[N][N]; 
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++) arr[i][j]=0;//��ʼ����i��ʯ�ӵ���j��ʯ�����ٷ���Ϊ0
	//��ֻ��һ��ʯ��ʱ��arr[i][i]=0�Ѷ���
	//��������ʯ��ʱ,�ܷ��ü�Ϊ����ʯ��֮�� 
	for(i=1;i<=n-1;i++) 
	{
		j=i+1;
		arr[i][j]=a[i]+a[j];  
	}
	//�����������ϵ�ʯ��ʱ
	for(k=3;k<=n;k++)
	 for(i=1;i<=n-k+1;i++)
	 {
	 	sum=0;
		j=i+k-1;//jΪ����i k-1�Ķѱ��
		for(int m=i;m<=j;m++) sum+=a[m];
		arr[i][j]=arr[i+1][j]+sum;//�������a[i+1][j]+sumΪ	arr[i][j]��Сֵ 
		//arr[i][j]����������Ƚϣ�ȡ��Сֵ
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

//�������ܹ�
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
 
