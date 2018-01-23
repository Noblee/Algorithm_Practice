#include <iostream>
#include <algorithm>
using namespace std;
//模拟短除法过程来解
int maxnum(int a[],int num)
{
	int buff =0;
	for(int i =0;i<num;i++)
	{
		if(a[i]>buff)
			buff=a[i];
	}
	return buff;
}
 int func(int a[],int n)
 {
 	int buff=1;
 	int maxx = maxnum(a,n);
 	for(int i =2;i<=maxx;i++)
 	{
 		int flag=0;
 		for(int j = 0; j < n; j++)
 		{
 			if(a[j]%i==0)
 			{
 				a[j]/=i;
 				flag=1;
 			}
 		}
 		if(flag==1)
 		{
 			buff = buff * i;
 			i = i-1;
 			maxx =  maxnum(a,n);
 		}
 	}
 	return buff;
 }

int main()
{
	int  a[] = {4,6,12,8,7};
	cout<<func(a,5);
	return 0;
}