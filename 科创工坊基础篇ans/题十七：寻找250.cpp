#include <iostream>

using namespace std;
int main()
{
	int n,count=1;
	while(cin>>n)
	{
		if(n==250) break;
		count++;
	}
	cout<<count<<endl; 
	return 0;
}
