#include <iostream>
#include <cstdio> 
#include <algorithm> 
#include <iomanip>

using namespace std;

//ÿ���±����� 
struct Moon
{
	double w,v;//�±��������ͼ�ֵ
	double density;//�±����Լ۱� 
};

//�±������Լ۱ȴӴ�С���� 
bool compare(Moon a,Moon b)
{
	return a.density>b.density;
}
Moon a[1001];
int main()
{
	int n,m,tmp,i;//nΪ�±�������mΪ�±��г�����
	double MaxV=0; 
	while(cin>>n>>m)
	{       
       for(i=0;i<n;i++) cin>>a[i].w;
       for(i=0;i<n;i++) cin>>a[i].v;
       for(i=0;i<n;i++) a[i].density=a[i].v/a[i].w;
	   sort(a,a+n,compare);//���±����Լ۱��ɴ�С���� 
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
