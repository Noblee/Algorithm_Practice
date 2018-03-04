#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;
int main()
{
	int GN,PN,LN,TN,i;
	GN=PN=LN=TN=0;
	string str;
	while(cin>>str)
	{
//		sort(str.begin(),str.end());
		for(i=0;i<str.length();i++)
		{
			if('a'<=str[i] && 'z'>=str[i]) str[i]-=32;
			if(str[i]=='G') GN++;
			if(str[i]=='L') LN++;
			if(str[i]=='P') PN++;
			if(str[i]=='T') TN++;
		}
		while(GN!=0 || PN!=0 || LN!=0 || TN!=0)
		{
			if(GN!=0) 
			{
				cout<<'G';
				GN--;
			}
			if(PN!=0) 
			{
				cout<<'P';
				PN--;
			}
			if(LN!=0) 
			{
				cout<<'L';
				LN--;
			}
			if(TN!=0) 
			{
				cout<<'T';
				TN--;
			}
		}
	}
	return 0;
}
