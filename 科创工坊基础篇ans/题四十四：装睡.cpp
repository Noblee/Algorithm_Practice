#include <iostream>

using namespace std;
int main()
{
	int N;
	string name;
	int b,p;
	cin>>N;
	while(N--)
	{
		cin>>name>>b>>p;
		if(b<15 || b>20 || p<50 || p>70) cout<<name<<endl;
	}
	return 0;
}
