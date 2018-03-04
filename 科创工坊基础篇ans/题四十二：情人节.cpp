#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str,L2,L14;
	int count=0;
	while(cin>>str && str!=".")
	{
		count++;
		if(count==2) L2=str;
		else if(count==14) L14=str;
	}
	if(count<2) cout<<"Momo... No one is for you ...";
	else if(2<=count && count<14) cout<<L2<<" is the only one for you...";
	else cout<<L2<<" and "<<L14<<" are inviting you to dinner...";
	return 0;
}
