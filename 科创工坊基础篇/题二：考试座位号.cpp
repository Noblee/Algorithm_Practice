#include <iostream>
#include <string>

using namespace std;
string s[1006];//׼��֤�� 
string str[1006];//�����Ի���λ�Ŵ��׼��֤���뿼����λ�� 
int a[1006];//�Ի���λ��  
string b[1006];//������λ��
int c[1006];//��ѯ�Ի���λ�� 
int main()
{
    int n,m,i,tmp;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
		   cin>>s[i]>>a[i]>>b[i];
		   str[a[i]]=s[i]+' '+b[i]; 
		}
		cin>>m;
		for(i=0;i<m;i++)
		   cin>>c[i];
		for(i=0;i<m;i++)
		   cout<<str[c[i]]<<endl; 
	}	
	return 0;
}
