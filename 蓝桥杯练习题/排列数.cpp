#include<iostream>
#include "algorithm"
using namespace std;
int main()
{
	int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,12,123,1123,122123,31231321};
	int n;
	cin >> n;
	do
	{
	} while (next_permutation(data, data + 16));
	for (int i = 0; i < 16; i++) {
		cout << data[i];
	}
	return 0;
}
