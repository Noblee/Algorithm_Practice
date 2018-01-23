#include <iostream>
#include <cstring>
#include <string> 
#include <vector>
#include <algorithm> 
using namespace std;
int a[100];//朋友圈人数 
int b[100][1000];//朋友圈id号 
bool flag[99999];//编号标志位 
bool flag1[99999];

string fun(int a)
{
	string s="00000";
	s[0]=s[0]+a/10000;
	s[1]=s[1]+a/1000%10;
	s[2]=s[2]+a/100%10;
	s[3]=s[3]+a/10%10;
	s[4]=s[4]+a%10;
	return s;
}
int main()
{
	int N,i,j,tmp,count=0;//朋友圈的个数
	vector<int> c;//查询编号向量 
	char num[6]; 
	memset(flag,false,sizeof(flag));
	memset(flag1,false,sizeof(flag1));
    cin>>N; 
	for(i=0;i<N;i++)
	{
	 cin>>a[i];//输入编号i对应的朋友圈人数
	 for(j=0;j<a[i];j++) 
	 {
	 cin>>b[i][j];//输入编号i对应的朋友id 
	 if(a[i]!=1) flag[b[i][j]]=true;	
	 }
	}
    int M;//带查询的人数
    cin>>M;
	for(i=0;i<M;i++) 
	{
		cin>>tmp;//输入带查询朋友的id
		c.push_back(tmp);	
	}
/*	sort(c.begin(),c.end());//对带查询编号数组排序 
	c.erase(unique(c.begin(),c.end()),c.end());//unique()函数将重复的元素放到vector的尾部，然后返回指向第一个重复元素的迭代器，再用erase函数擦除从这个元素到最后元素的所有的元素
*/	
	for(i=0;i<c.size();i++) 
	{
		if(flag[c[i]]==false)
		{
			cout<<fun(c[i]);
			flag1[c[i]]=true;
			count++;
			break;
		}
	}
	
	for(j=i+1;j<c.size();j++) 
	{
		if(flag[c[j]]==false)
		{
			if(!flag1[c[j]])
			{
				cout<<' '<<fun(c[j]);
		     	count++;
			}
		flag1[c[j]]=true;
		}
	}
	if(count==0) cout<<"No one is handsome";
	  
	return 0;
} 
