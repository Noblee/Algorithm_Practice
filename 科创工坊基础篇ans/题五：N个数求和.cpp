#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
long long fz[102];
long long fm[102];
using namespace std;

//求两数最大公约数 
long long fun(long long a,long long b)
{
	return b==0?a:fun(b,a%b);
}
int main()
{
	long long n,i,x,y,z;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld/%lld",&fz[i],&fm[i]);
		}
		for(i=0;i<n-1;i++)
		{
			x=fm[i+1]/fun(fm[i],fm[i+1])*fz[i]+fm[i]/fun(fm[i],fm[i+1])*fz[i+1];//x为两分数相加后的分子
			y=fm[i]*fm[i+1]/fun(fm[i],fm[i+1]);//y为两数相加后的分母
			fz[i+1]=x;
			fm[i+1]=y;
		}
		if(x%y==0) cout<<x/y<<endl;
		else if(x==0) cout<<0<<endl;
		else if(abs(x)/y>1) 
		{
			cout<<x/y<<' ';
			x=abs(x-x/y*y);
			z=fun(x,y);
			cout<<x/z<<'/'<<y/z<<endl;
		}
		else
		{
			z=fun(abs(x),y);
			cout<<x/z<<'/'<<y/z<<endl;	
		}			
	}
	return 0;
} 
