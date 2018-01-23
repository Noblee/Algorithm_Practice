#include <iostream>

using namespace std;
int main()
{
	int N,count_odd=0,count_even=0;
	while(cin>>N)
	{
		int i;
		while(N--)
		{
			cin>>i;
			if(i%2==1) count_odd++;
			else count_even++;
		}
		cout<<count_odd<<' '<<count_even<<endl;
	}
	return 0;
}
