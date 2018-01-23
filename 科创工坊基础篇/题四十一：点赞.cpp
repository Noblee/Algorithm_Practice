#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct zan
{
	int p;
	int count;
};


bool cmp(zan a,zan b)
{
	return a.count>b.count;
}

int main()
{
	int n,m,tmp,i=0;
	zan a[1002]={};
	cin>>n;
	while(n--)
	{
		cin>>m;
		while(m--)
		{
			cin>>tmp;
			a[tmp].count++;
			a[tmp].p=tmp;
		} 
	}
	sort(a,a+1002,cmp);
	int t=a[0].p;
	for(i=0;i<1002;i++)
	{
		if(a[i].count==a[i+1].count)
		{
			if(a[i+1].p>a[i].p) t=a[i+1].p;		
		}
		else break;
	} 
	cout<<t<<' '<<a[0].count;
	return 0;
}
