#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[4];//存放年份
//计算年份中不同数字的个数 
int diffN(int b[4])
{
	int c[4];
	int i,count=1;
	for(i=0;i<4;i++)
	{
		c[i]=b[i];
	}
	sort(c,c+4);
	for(i=0;i<3;i++)
	{
		if(c[i]!=c[i+1]) count++;
	}
	return count;
}

int main()
{
	int y,n,anw=0,i;
	while(cin>>y>>n)
	{
	  	a[0]=y/1000;
	  	a[1]=y/100%10;
	    a[2]=y%100/10;
		a[3]=y%10;
    	while(diffN(a)!=n)
		{
		   anw++;
		   a[3]++;
	       a[2]+=a[3]/10;
	       a[1]+=a[2]/10; 
	       a[0]+=a[1]/10;
           a[3]%=10;
	       a[2]%=10;
	       a[1]%=10;
		} 
		cout<<anw<<' ';
		for(i=0;i<4;i++) cout<<a[i];
		cout<<endl;
	} 
	return 0;
}
