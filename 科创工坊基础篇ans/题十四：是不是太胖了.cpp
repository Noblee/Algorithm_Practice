#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
	int t;
	float sw;
	while(cin>>t)
	{
		sw=(t-100)*0.9*2;
		cout<<fixed<<setprecision(1)<<sw<<endl;
	}
	return 0;
}
