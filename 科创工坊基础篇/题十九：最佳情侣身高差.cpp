#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n,i;
	double tall[10];
	char sex[10];
	while(cin>>n)
	{
		for(i=0;i<n;i++) 
		{
			cin>>sex[i]>>tall[i];
			if(sex[i]=='F') tall[i]*=1.09;
			else tall[i]/=1.09;
		}
		for(i=0;i<n;i++) 
		{
			cout<<fixed<<setprecision(2)<<tall[i]<<endl;
		}
	}
	return 0;
}
