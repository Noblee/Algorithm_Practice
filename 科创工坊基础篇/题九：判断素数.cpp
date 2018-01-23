#include <iostream>
#include <cmath>
#include <string>

using namespace std;
string str[10];
int main()
{
	int n,i,j,k=0;
	bool flag;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>i;
			flag=false;
			if(i==2)  
			{
				str[k]="Yes";
				k++;
			}
			else if(i==1) 
			{
			    str[k]="No";
				k++;	
			}
			else
			{
				for(j=2;j<sqrt(i)+1;j++)
			  {
			  	if(i%j==0) 
				  {
				  	str[k]="No";
				  	k++;
				  	flag=true;
				  	break;
				  }		
			  }
			  if(!flag)
			  {
			  		str[k]="Yes";
				  	k++;
			  }
			}
		}
		    for(j=0;j<k;j++)
               cout<<str[j]<<endl;
               k=0;
	}
	return 0;
}
