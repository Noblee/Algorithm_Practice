#include <iostream>
#include <string>
#include <cstring> 
using namespace std;
char telnum[11]; 
bool flag[10];
int a[10];
int main()
{
	int i,j=0,k=0,count=0;
	char tmp[20]={'\0'},po[30]={'\0'};
	string str,str1;
	memset(flag,false,sizeof(bool)*10);
	while(cin>>telnum)
	{
		for(i=0;i<11;i++)
		{
			flag[telnum[i]-'0']=true;
		}
		for(i=9;i>=0;i--)
		{
			if(flag[i]==true)
			{
				tmp[j++]=i+'0';
				tmp[j++]=',';
			}
		}
		str=tmp;
	    str.erase(j-1,1);
		cout<<"int[] arr = new int[]{"<<str<<"};"<<endl;
		for(i=0;i<str.length();i++)
		{
			if(str[i]==',') str.erase(i,1);//É¾³ýÔ­×Ö·û´®ÖÐµÄ¶ººÅ 
		}	
        for(i=0;i<11;i++)
		{
			for(j=0;j<str.length();j++)
			{
				if(telnum[i]==str[j])
				{
					po[k++]=j+'0';
					po[k++]=',';
					break;
				}
			}
		}
		str1=po;
		str1.erase(k-1,1);
		cout<<"int[] index = new int[]{"<<str1<<"};"<<endl;
		}
	return 0;
} 
