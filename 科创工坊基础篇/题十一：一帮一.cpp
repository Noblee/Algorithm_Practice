#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string name[51];
int sex[51];
bool flag[51];
int main()
{
	int N,i,j,count=0;
	memset(flag,true,sizeof(bool)*51);
	while(cin>>N)
	{
		for(i=0;i<N;i++)
		{
			cin>>sex[i]>>name[i];
		}
		for(i=0;i<N;i++)
		{
			for(j=N-1;j>0;j--)
			{
				if(flag[j]&&(sex[i]^sex[j])) 
				{
				 cout<<name[i]<<' '<<name[j]<<endl;
				 flag[j]=false;
				 count++;
				 break;	
				}
			}
			if(count*2==N) break;
		}
	}
	
	return 0;
}
