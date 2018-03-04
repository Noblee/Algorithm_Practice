#include <iostream>
#include <string>

using namespace std;
string s[1006];//准考证号 
string str[1006];//根据试机座位号存放准考证号与考试座位号 
int a[1006];//试机座位号  
string b[1006];//考试座位号
int c[1006];//查询试机座位号 
int main()
{
    int n,m,i,tmp;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
		   cin>>s[i]>>a[i]>>b[i];
		   str[a[i]]=s[i]+' '+b[i]; 
		}
		cin>>m;
		for(i=0;i<m;i++)
		   cin>>c[i];
		for(i=0;i<m;i++)
		   cout<<str[c[i]]<<endl; 
	}	
	return 0;
}
