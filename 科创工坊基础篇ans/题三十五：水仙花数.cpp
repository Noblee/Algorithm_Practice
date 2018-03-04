#include <iostream>
#include <cmath>

bool fun(int n)
{
	if(n==pow(n/100,3)+pow(n%100/10,3)+pow(n%10,3)) return true;
	else return false;
}
using namespace std;
int main()
{
	int a,b,i;
	bool flag=false;
	while(cin>>a>>b)
	{
		for(i=a;i<=b;i++)
		{
			if(fun(i)) 
			{
			cout<<i;
			flag=true;
			break;	
			}
		}
		for(int j=i+1;j<=b;j++)
		{
			if(fun(j)) 
			{
			cout<<' '<<j;	
			}
		}
		if(!flag) cout<<"no";
		cout<<endl; 
	} 
	return 0;
}
