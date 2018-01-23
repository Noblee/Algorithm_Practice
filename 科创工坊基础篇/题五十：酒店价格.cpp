#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//定义一个结构体变量保存价格区间的起始日期，结束日期以及区间价格 
struct Hotel
{
	int begin;
	int end;
	int price;
};

//比较函数，从小打到排列 
bool cmp(Hotel a,Hotel b)
{
	return a.begin<b.begin;
}

int main()
{
    Hotel a[400];//定义最大价格区间数不超过400，以一年365天为基准
    int i=0;
    bool flag=true;
	while(1)
	{
	    cin>>a[i].begin>>a[i].end>>a[i].price;
		if(a[i].begin==0 && a[i].end==0 && a[i].price==0) break;
		else i++;
	} 
	int n=i;
	sort(a,a+n,cmp);//按照价格区间的起始日期从小到大排列
	int B=a[0].begin;
    int E=a[0].end;
	for(i=0;i<n;i++)
	{
		if(a[i].end>=a[i+1].begin-1 && a[i].price==a[i+1].price)
		{
			E=a[i+1].end;   
			continue;      
		}
		if(a[i].end==a[i+1].begin && a[i].price!=a[i+1].price) 
		{
		  if(B==E) B=E=E-1;
		  else E=E-1;

		}
		if(flag) 
			{
				cout<<'['<<B<<','<<E<<','<<a[i].price<<']';
				flag=false;
			}
		else cout<<','<<'['<<B<<','<<E<<','<<a[i].price<<']';
		B=a[i+1].begin;
		E=a[i+1].end;
	}
	return 0;
}
