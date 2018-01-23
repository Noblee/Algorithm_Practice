/*
首先，（0，n）也是必胜态，（n，0），（n，n）都是必胜态，接下来就是（1，2），先手不管怎么取，后手都赢。
同理，衍生出（1，n），（n，2），（n+1，n+2）(n>=3)等必胜态，然后（2，1）根据对称也是一样的.
接下来的必败态分别为（3，5）、（4，7）、（6，10）、（8，13）、（9，15）、（11，18）、（12，20）。
可以看出a0=b0=0,ak是未在前面出现过的最小自然数,而 bk=ak+k。
我们可以看出一下规律：
ak =[k（1+√5）/2]，bk=ak+k （k=0，1，2，...n 方括号表示取整函数）,其中（1+√5）/2是黄金分割数。
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int A,B;
	double k=(1.0+sqrt(5.0))/2.0;
	while(1)
	{
		cin>>A>>B;
		int t=max(A,B)-min(A,B);
		int ak=(int)(t*k);
		if(ak==min(A,B)) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
} 
