#include <iostream>
#include <cstring>
#include <string> 
#include <vector>
#include <algorithm> 
using namespace std;
int a[100];//����Ȧ���� 
int b[100][1000];//����Ȧid�� 
bool flag[99999];//��ű�־λ 
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
	int N,i,j,tmp,count=0;//����Ȧ�ĸ���
	vector<int> c;//��ѯ������� 
	char num[6]; 
	memset(flag,false,sizeof(flag));
	memset(flag1,false,sizeof(flag1));
    cin>>N; 
	for(i=0;i<N;i++)
	{
	 cin>>a[i];//������i��Ӧ������Ȧ����
	 for(j=0;j<a[i];j++) 
	 {
	 cin>>b[i][j];//������i��Ӧ������id 
	 if(a[i]!=1) flag[b[i][j]]=true;	
	 }
	}
    int M;//����ѯ������
    cin>>M;
	for(i=0;i<M;i++) 
	{
		cin>>tmp;//�������ѯ���ѵ�id
		c.push_back(tmp);	
	}
/*	sort(c.begin(),c.end());//�Դ���ѯ����������� 
	c.erase(unique(c.begin(),c.end()),c.end());//unique()�������ظ���Ԫ�طŵ�vector��β����Ȼ�󷵻�ָ���һ���ظ�Ԫ�صĵ�����������erase�������������Ԫ�ص����Ԫ�ص����е�Ԫ��
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
