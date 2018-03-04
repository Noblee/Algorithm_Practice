#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a,b;
	while(cin>>a)
	{
		int i;
		for(i=a.length()-4;i<a.length();i++)
		  b+=a[i];
		b+='-';
		for(i=0;i<2;i++)
		  b+=a[i];
		b+='-';
		for(i=3;i<5;i++)
		  b+=a[i];
		cout<<b<<endl;
	}
	return 0;
}
