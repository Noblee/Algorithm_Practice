#include <iostream>
#include <cstring>

using namespace std;
string s[1000];  //���ÿ�������*�� 
//��ӡ�Գ�*�� 
int Print_stars(int a,char b)
{
    int i,j,k=0,t=0,tmp;
	for(i=a;i>=1;i=i-2)
	{	
	    tmp=t;	
		j=i;
		while(tmp--)
		{
		  s[k]+=' ';
		}
		while(j--)
		{
			s[k]+=b;
		}
		k++;
		t++;
	}
	t--;
	t--;
	if(a>=3)
	{
		for(i=3;i<=a;i=i+2)
	{
		tmp=t;
		j=i;
		while(tmp--)
		{
		  s[k]+=' ';
		}
		while(j--)
		{
			s[k]+=b;
		}
		k++;
		t--;
	}	
	}
	return k;
}

int main()
{
	int n,m,i,j,k,tmp;
	char c;
	while(cin>>n>>c)
	{
		tmp=1;
		for(i=3;;i=i+2)
		{
			tmp+=2*i;
			if(tmp>=n) break;
		}
		if(tmp==n)
		{
		  m=Print_stars(i,c);
		  for(i=0;i<m;i++)
		 cout<<s[i]<<endl;	
		}
		else
		{
		 j=i-2;	
		 m=Print_stars(j,c);
		 for(i=0;i<m;i++)
		      cout<<s[i]<<endl;	
		 cout<<n-tmp+2*(j+2)<<endl;
		}
		//����ַ��� 
		for(i=0;i<m;i++)
           s[i].clear();		 
	}
	return 0;
}
