#include <iostream>
#include <string> 
#include <sstream>
using namespace std;

int f(string str)
{
	int i,sum=0;
	for(i=0;i<str.size();i++) sum+=str[i]-'0';
	return sum;
}

int g(int a)
{
	int count=0;
	while(a!=0)
	{
		count+=a%2;
		a=a/2;
	}
	return count;
}
int main()
{
	int n,i,num=0;	
	string s;
	int b;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		stringstream ss;//stringstream可以将不同类型数据转换为string类型数据 
		ss<<i; 
		ss>>s;
		if(f(s)==g(i)) 
		{
			num++;    
		}
	}
	cout<<num;
	return 0;
}
