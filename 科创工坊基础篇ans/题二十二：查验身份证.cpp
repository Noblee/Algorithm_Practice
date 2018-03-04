#include <iostream>
#include <string>
using namespace std;
int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char b[11]={'1','0','X','9','8','7','6','5','4','3','2'};
string per_num[102];

//Ð£Ñéº¯Êý
bool fun(string str)
{
	int count=0;
	for(int i=0;i<str.length()-1;i++)
	{
		count+=(str[i]-'0')*a[i];
	}
	if(b[count%11]==str[str.length()-1]) return true;
	else return false;
	
} 
int main()
{
	int n,i,cnt=0;
	while(cin>>n)
	{
	   for(i=0;i<n;i++)
	      cin>>per_num[i];
	   for(i=0;i<n;i++)
	   {
	   	  if(fun(per_num[i])) 
			 {
			 	cnt++;
			 	continue;
			 }
		  else cout<<per_num[i]<<endl;	
	   }
	   if(cnt==n) cout<<"All passed"<<endl;

	}
	return 0;
}
