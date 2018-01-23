#include <iostream>
#include <string>
using namespace std;
int main()
{
	int tmp,count;
	string time;
	while(cin>>time)
	{
		count=(time[0]-'0')*10+time[1]-'0';
		if(count<12) cout<<"Only "<<time<<".  Too early to Dang."<<endl;
		else if(count==12)
		{
			if((time[3]-'0')*10+time[4]-'0'>0) cout<<"Dang"<<endl;
			else cout<<"Only "<<time<<".  Too early to Dang."<<endl;
		}
		else
		{
			if((time[3]-'0')*10+time[4]-'0'>0) count-=11;
			else count-=12;
			while(count--) cout<<"Dang";
		}
	}
	return 0;
}
