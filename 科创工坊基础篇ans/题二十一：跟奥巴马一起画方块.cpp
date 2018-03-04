#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	char c;
	while(cin>>n>>c)
	{
		int row;//行数 
		float tmp=n/2.0;
		int col=(int)(tmp+0.5);//列数
		while(col--)
		{  
		    row=n;
			while(row--) cout<<c;
			cout<<endl;
		} 
	}
	return 0;
}
