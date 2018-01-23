#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a,b;
	float c; 
	while(cin>>a>>b)
	{
		c=a*1.0/b;
		if(b==0) cout<<a<<'/'<<0<<'='<<"Error"<<endl;
		else if(b<0) cout<<a<<'/'<<'('<<b<<')'<<'='<<fixed<<setprecision(2)<<c<<endl;
		else cout<<a<<'/'<<b<<'='<<fixed<<setprecision(2)<<c<<endl;
	} 
	return 0;
} 
