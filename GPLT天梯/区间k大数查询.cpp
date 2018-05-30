#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char Cmap[1005][1005];
int main()
{
	int n,m;
	char s[1005];
	cin >> n;
	getchar(); //用这个来接收空格
	gets(s);
	int len = strlen(s);
	m = len/n;
	if(len%n != 0) m++;
	int i = 0;
	for(int k = m-1; k >= 0; k--){
		for(int j = 0; j < n; j++){
			if(i < len)
				Cmap[j][k] = s[i++];
			else
				Cmap[j][k] = ' '; //当长度超过len时直接赋值空格。
		}
	}
	for(int j = 0; j < n; j++){ // 最后输出。
		for(int k = 0; k < m; k++)
			cout << Cmap[j][k];
		cout << endl;
	}
	return 0;
}