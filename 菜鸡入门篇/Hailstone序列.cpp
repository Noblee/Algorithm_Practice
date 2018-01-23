 #include <iostream>
using namespace std;

void recursion(int num)
{
	if(buff<=1)
	{
		v.push_back(1);
		return;
	}
	else if(buff%2==0)
	{
		v.push_back(num);
		recursion(num/2);
		return;
	}
	else 
	{
		v.push_back(num);
		recursion(3*num+1);
	}
}
int main()
{
	vector<int> v(0);
	int buff;
	cin>>buff;
	recursion(buff);
	for(int i =0;i<v.size(),i++)
	{
		cout<<v[i];
	}
	return 0;
}