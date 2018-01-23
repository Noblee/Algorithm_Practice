#include <iostream>
#include <algorithm>

using namespace std;
int a[100002];

int main()
{
	int n,i,j,middle,ans=0;
	while(cin>>n)
	{
		for(i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
//		middle=n/2;
		if(n%2==0)
		{
			cout<<"Outgoing #: "<<n/2<<endl<<"Introverted #: "<<n/2<<endl;
			for(i=0,j=n-1;i<j;i++,j--)
			  ans+=a[j]-a[i];
			cout<<"Diff = "<<ans<<endl;			
		}
	    else
	    {
	    	cout<<"Outgoing #: "<<(n+1)/2<<endl<<"Introverted #: "<<(n-1)/2<<endl;
	    	for(i=0,j=n-1;i!=j;i++,j--)
			  ans+=a[j]-a[i];
			ans=ans+a[n/2];
			cout<<"Diff = "<<ans<<endl;	
	    }
	    ans=0;
	}
	return 0;
}
