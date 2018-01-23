#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int N,i,j,k=0,p=0;
	string s;
	char str[1000]; 
	scanf("%d\n",&N);
//	cin>>c;
	getline(cin,s);//输入待排版的字符串 
	double tmp=s.size()*1.0/N;
	int column=tmp>s.size()/N?(tmp+1):tmp;//字符串排版的列数
//	cout<<column;
		while(p<N)
	{
		j=p;
        int m=column;
        while(j<s.size())
        {
        	str[m-1]=s[j];
        	j=j+N;
        	m--;
        }
        for(i=0;i<column;i++) cout<<str[i];
        str[0]=' ';
        k++;
        p++;
        if(p<N) cout<<endl;
	} 
	return 0;
} 
