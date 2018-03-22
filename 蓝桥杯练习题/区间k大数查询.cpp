#include<bits/stdc++.h>
using namespace std;
vector<int> data;
bool compare(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	cin>>n;
	for(int i =0;i<n;i++)
	{
		int temp;
		cin>>temp;
		data.push_back(temp);
	}
	int m;
	cin>>m;
	for(int i =0;i<m;i++)
	{
		int l,r,k;
		cin>>l>>r>>k;
		vector<int> temp = data;
		sort(temp.begin()+l-1,temp.begin()+r,compare);
		cout<<temp[l+k-2]<<endl;
	}	
	return 0;
}
