#include<iostream>
#include "algorithm"
using namespace std;
bool comp(int a, int b)
{
	return a>b;
}
//大于降序
int main()
{
	int a[]={1,312,213,123,1212,434324,3242332,31,122,31};
	sort(a,a+sizeof(a)/sizeof(int),comp);
	for(int i =0;i<sizeof(a)/sizeof(int);i++)
		cout<<a[i]<<" ";
	return 0;
}