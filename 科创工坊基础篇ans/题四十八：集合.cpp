#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	vector<int> a;
	int n,m,i;
	cin>>n>>m;
	int tmp;
	while(n--)
	{
		cin>>tmp;
		a.push_back(tmp);       
	}
	while(m--)
	{
		cin>>tmp;
		a.push_back(tmp);   
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());//去掉向量里面重复的元素 
	for(i=0;i<a.size()-1;i++) cout<<a[i]<<' ';
	cout<<a[i];
	return 0;
}
