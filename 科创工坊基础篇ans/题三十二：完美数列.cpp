#include <iostream>
#include <algorithm>
using namespace std;
long long a[100002];
int main()
{
	long long N,p,i,j,m,M,tmp,t,count;
	while(cin>>N>>p)
	{
        count=0;	
		for(i=0;i<N;i++) cin>>a[i];
		sort(a,a+N);
		for(i=0;i<N;i++)
         for(j=i+count+1;j<N;j++)//增加步长搜索，减小搜索空间 
         {
			 if(a[j]<=a[i]*p) count++;
         	else break;
         }
         cout<<count+1<<endl;
	}
	return 0;
}
