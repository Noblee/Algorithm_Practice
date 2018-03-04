#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int main()
{
	int N,count=0; 
	char c;
	string s;
	cin>>N>>c;
	while(getchar()!='\n');
	getline(cin,s);//输入带空格的string 	
	if(N>s.size())
	{
		int tmp=N-s.size();
		while(tmp--) cout<<c;
		cout<<s; 
	}
	else
	{
		int len=s.size();
		string sc=s.erase(0,0+len-N);
		cout<<sc;
	}
	return 0;
}
