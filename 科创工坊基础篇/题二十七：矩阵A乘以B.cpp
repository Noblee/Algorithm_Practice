#include <iostream>
#include <cstring>
using namespace std;
int A[100][100];
int B[100][100];
int ans[100][100];
int main()
{
	int r1,c1,r2,c2,i,j,k;
	while(cin>>r1>>c1)
	{
		memset(A,0,sizeof(int)*100*100);
		memset(B,0,sizeof(int)*100*100);
		memset(ans,0,sizeof(int)*100*100);
		for(i=0;i<r1;i++)
		 for(j=0;j<c1;j++)
		   cin>>A[i][j];
		   
		cin>>r2>>c2;
		for(i=0;i<r2;i++)
		 for(j=0;j<c2;j++)
		   cin>>B[i][j];
		if(c1!=r2) 
		{
		 cout<<"Error: "<<c1<<" != "<<r2;
		 break;	
		}
		else
		{
		for(i=0;i<r1;i++)
		 for(j=0;j<c2;j++)
		  for(k=0;k<c1;k++)
		    ans[i][j]+=A[i][k]*B[k][j];
		    
		cout<<r1<<' '<<c2<<endl;		    
		for(i=0;i<r1;i++)
		{
			cout<<ans[i][0];
		for(j=1;j<c2;j++)
		   cout<<' '<<ans[i][j];
		cout<<endl;
		}		   
		} 		
	}
	return 0;
}
