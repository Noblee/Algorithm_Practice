#include <iostream>
//模拟纸上除法运算 
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		long long result=1;
		int count=1;
		while(result<n)
		{
			result=result*10+1;
			count++;
		}
		while(result%n!=0)
		{
		    cout<<result/n;
			result%=n; 
			result=result*10+1;
			count++;
		} 
		cout<<result/n<<' '<<count<<endl;
	} 
	return 0;
}
