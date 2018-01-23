#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	bool flag=false;
	int len1=min(a1.size(),a2.size());
	int len2=min(b1.size(),b2.size()); 
	//输出星期与一天的时数 
	for(int i=0;i<len1;i++)
	{
		if(a1[i]==a2[i] && 'A'<=a1[i] && a1[i]<='G' && !flag) 
		{
			switch(a1[i])
			{
				case 'A':cout<<"MON"<<' ';break;
				case 'B':cout<<"TUE"<<' ';break;
				case 'C':cout<<"WED"<<' ';break;
				case 'D':cout<<"THU"<<' ';break;
				case 'E':cout<<"FRI"<<' ';break;
				case 'F':cout<<"SAT"<<' ';break;
				case 'G':cout<<"SUN"<<' ';
			}
			flag=true;
			i++;
		}
		if(a1[i]==a2[i] && flag)
		{
			if('0'<=a1[i] && a1[i]<='9') cout<<'0'<<a1[i]<<':';
			else if('A'<=a1[i] && a1[i]<='N') 
			{
				int tmp=10+a1[i]-'A';
				cout<<tmp<<':'; 
			}
			break;
		}
	}
	
	//输出一天的分数 
	for(int i=0;i<len2;i++)
	{
		if('A'<=b1[i] && b1[i]<='Z' || 'a'<=b1[i] && b1[i]<='z' && b1[i]==b2[i]) 
		{
			if(i<=9) cout<<'0'<<i;
			else cout<<i;
			break;
		}
	}
	return 0;
}
