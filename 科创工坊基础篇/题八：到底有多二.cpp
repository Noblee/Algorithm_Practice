#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	string str;
	float a,ans;
	int tmp,count=0;
	while(cin>>str)
	{
		if(str[0]=='-') 
		{
		a=1.5;
		tmp=str.length()-1;	
		}
		else 
		{
		a=1.0;
		tmp=str.length();		
		}
		
		if((str[str.length()-1]-'0')%2==0) a=a*2;
	    
	    int n=str.length(),i=0;
	    while(n--)
	    {
	    	if(str[i]=='2') count++;
	    	i++;
	    }
	    ans=count*a/tmp*100;
	    cout<<fixed<<setprecision(2)<<ans<<'%'<<endl;
	    count=0;
	} 
	return 0;
}
