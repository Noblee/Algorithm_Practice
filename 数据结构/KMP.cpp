#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void get_next(string &T, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length()) {
// cout << " ";
// for (int i = 0; i < T.length(); ++i){cout << T[i];}
// 		cout << endl;
// 		for (int ii = 0; ii < (int)T.length(); ii++)
// 		{
// 			if (j == ii)
// 				cout << "j";
// 			else if (i == ii)
// 				cout << 'i';
// 			else
// 				cout << " ";
// 		}
		// printf("\n");
		// for (int ii = 1; ii <= (int)i; ii++) {
		// 	cout << next[ii];
		// }
		// printf("\n");
		if (j == 0 || T[i] == T[j])
		{
			// if (j == 0)
			// 	cout << "j退到头了！\n";
			++j;
			++i;
			//重新匹配的位置的值必须不相同才有意义
			//如果相同就去上一次可以在这个位置匹配的位置
			if (T[i] != T[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
		{
			j = next[j];
			// cout << "\nj向后退j = next[j]！\n\n";
		}
	}
}
int main(int argc, char const *argv[])
{
	string str = " aaaab";
	int * p = (int *)malloc((str.length()+1) * sizeof(int));
	get_next(str, p);
	for (int i = 1; i <=str.length(); i++)
		cout << p[i] << " ";
	return 0;
}