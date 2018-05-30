#include <iostream>
using namespace std;
//语义：借用z把x上的n个放到y上
void rec(int n ,char x,char y, char z)
{
	if(n>0)
	{
		rec(n-1,x,z,y);
		cout<<"Move dish No." <<n<<" from pile "<<x<<" to "<<y<<endl;
		rec(n-1,z,y,x);
	}
}
int main()
{
	rec(3,'A','B','C');
	return 0;
}