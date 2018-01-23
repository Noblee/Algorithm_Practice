#include <iostream>
#include <cstdio> 
#include <algorithm> 
#include <iomanip>

using namespace std;

//每种月饼参数 
struct Moon
{
	double w,v;//月饼的重量和价值
	double density;//月饼的性价比 
};

//月饼按照性价比从大到小排列 
bool compare(Moon a,Moon b)
{
	return a.density>b.density;
}
Moon a[1001];
int main()
{
	int n,m,tmp,i;//n为月饼种数，m为月饼市场需求
	double MaxV=0; 
	while(cin>>n>>m)
	{       
       for(i=0;i<n;i++) cin>>a[i].w;
       for(i=0;i<n;i++) cin>>a[i].v;
       for(i=0;i<n;i++) a[i].density=a[i].v/a[i].w;
	   sort(a,a+n,compare);//按月饼的性价比由大到小排序 
	   for(i=0;i<n;i++)
	   {
		   if(a[i].w>m) 
		   {
		   	MaxV+=m/a[i].w*a[i].v;
		   	break;
		   }
		   else
		   {
		   	MaxV+=a[i].v;
		   	m=m-a[i].w;
		   }
	   }
	   cout<<fixed<<setprecision(2)<<MaxV<<endl;    
	} 
	return 0;
}
