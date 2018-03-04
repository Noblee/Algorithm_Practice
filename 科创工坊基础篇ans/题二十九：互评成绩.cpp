#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
int score[10002];

int main()
{
	int N,K,M,i,j;
	int tmp[10];
	double ans[10002];
	vector<int>v;
	while(cin>>N>>K>>M)
	{
		memset(ans,0,sizeof(double)*10002);
		for(i=0;i<N;i++)
		{
		 for(j=0;j<K;j++) 
		 {
		 	cin>>tmp[j];
			v.push_back(tmp[j]);
		 }
		 sort(v.begin(),v.end());
		 for(j=1;j<K-1;j++) ans[i]+=v[j];
		 ans[i]=ans[i]/(K-2);
		 v.clear();//只清除数据不清除栈空间 
		}
        sort(ans,ans+N);//从小打到排列 
        reverse(ans,ans+N);//从大到小排列 
        cout<<fixed<<setprecision(3)<<ans[M-1]; 
        for(i=M-2;i>=0;i--)
        {
        	cout<<' '<<fixed<<setprecision(3)<<ans[i]; 
        }
        cout<<endl;
	}
	return 0;
}
