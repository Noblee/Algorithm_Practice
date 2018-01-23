#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int a[1001]; 

void A1(int a[],int m)
{
	int i,sum=0;
	for(i=0;i<m;i++)
	{
		if(a[i]%10==0) sum+=a[i];
	}
	if(sum==0) cout<<'N'<<' ';
	else cout<<sum<<' ';
}

void A2(int a[],int m)
{
	int i,t=1,count=0,sum=0;
	for(i=0;i<m;i++)
	{
		if(a[i]%5==1) 
		{
			a[i]=a[i]*t;
			sum+=a[i];
			t=t*(-1);
			count++;
		}
	}
	if(count==0) cout<<'N'<<' ';
	else cout<<sum<<' ';
}

void A3(int a[],int m)
{
	int i,count=0;
	for(i=0;i<m;i++)
	{
		if(a[i]%5==2) count++;
	}
	if(count==0) cout<<'N'<<' ';
	else cout<<count<<' ';
}

void A4(int a[],int m)
{
	int i,count=0;
	double sum=0;
	for(i=0;i<m;i++)
	{
		if(a[i]%5==3)
		{
			sum+=a[i];
			count++;
		}
	}
	if(count==0) cout<<'N'<<' ';
	else cout<<fixed<<setprecision(1)<<sum/count<<' ';
}

void A5(int a[],int m)
{
	int i,max=0;
	for(i=0;i<m;i++)
	{
		if(a[i]%5==4)
		{
			if(a[i]>max) max=a[i];
		}
	}
	if(max==0) cout<<'N'<<endl;
	else cout<<max<<endl;
}

int main()
{
	int n,i;
	while(cin>>n)
	{
		for(i=0;i<n;i++) cin>>a[i];
		A1(a,n);
		A2(a,n);
        A3(a,n);
        A4(a,n);
        A5(a,n);
	}
	return 0;
}
