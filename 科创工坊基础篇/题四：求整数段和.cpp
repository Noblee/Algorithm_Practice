#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	int a,b,count=0,sum=0;
	while(cin>>a>>b)
	{
		for(int i=a;i<=b;i++)
		 {
		 	cout<<setw(5)<<i;//Ĭ���Ҷ��� 
		 	sum+=i;
		 	if(++count%5==0) cout<<endl;
		 }	
		 if(count%5==0) cout<<"Sum = "<<sum<<endl; //ע�������ʽ����Ҫ����һ��	 
         else cout<<endl<<"Sum = "<<sum<<endl;
	}
	return 0;
} 
