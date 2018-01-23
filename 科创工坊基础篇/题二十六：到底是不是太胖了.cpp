#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int N;
	double H,W;
	while(cin>>N)
	{
		while(N--)
		{
			cin>>H>>W;
			double tmp=(H-100)*0.9*2;
			if(abs((tmp-W))<0.099*tmp) cout<<"You are wan mei!"<<endl;//* 
			else if(tmp>W) cout<<"You are tai shou le!"<<endl;
			else cout<<"You are tai pang le!"<<endl;			
		}
	}
	return 0;
}
