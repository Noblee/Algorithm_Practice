#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
/*通过单词组成可发现：0的特征为Z，2的特征为W，4的特征为U,6的特征为X，8的特征为G
step one：统计数字0，2，4，6，8个数 
step two：去除已计算得到的上述数字 
step three：统计数字3，5，7个数（ 7的特征为S，5的特征为F，3的特征为H） 
step four：去除已计算得到的上述数字
step five：统计数字1，9个数（ 1的特征为O，9的特征为I）  
*/
using namespace std;
string arr[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
string a[102];
//int num[10]={2,3,4,5,6,7,8,9,0,1};
int c[5000];//存放字符串中数字分身前的中文数字 
int main()
{
	int T,i,j,t,count;//count用来统计一个字符串中英文数字的个数 
	int b[26];//数组b用来统计字符串中字母A-Z的个数 
	while(cin>>T)
	{
		for(i=0;i<T;i++) cin>>a[i];
        for(i=0;i<T;i++)
        {
        	memset(b,0,sizeof(int)*26);//初始化b数组各元素为0
			memset(c,0,sizeof(int)*5000);//初始化b数组各元素为0  
			count=0; 
        	for(j=0;j<a[i].size();j++) b[a[i][j]-'A']++;
        	//对应不同的数字单词，并减去里面对应的字母 
        	if(b['Z'-'A'])//0->2
        	{
        		t=b['Z'-'A'];
        		for(int k=0;k<arr[0].size();k++) b[arr[0][k]-'A']-=t; //减去数字字母中字母个数 
        		while(t--) c[count++]=2; 
        	}
        	
        	if(b['W'-'A'])//2->4
        	{
        		t=b['W'-'A'];
				for(int k=0;k<arr[2].size();k++) b[arr[2][k]-'A']-=t; 
				while(t--) c[count++]=4; 
        	}
        	
        	if(b['U'-'A'])//4->6
        	{
        		t=b['U'-'A'];
				for(int k=0;k<arr[4].size();k++) b[arr[4][k]-'A']-=t; 
				while(t--) c[count++]=6; 
        	}
        	
        	if(b['X'-'A'])//6->8
        	{
        		t=b['X'-'A'];
				for(int k=0;k<arr[6].size();k++) b[arr[6][k]-'A']-=t; 
				while(t--) c[count++]=8; 
        	}
        	
        	if(b['G'-'A'])//8->0
        	{
        		t=b['G'-'A'];
				for(int k=0;k<arr[8].size();k++) b[arr[8][k]-'A']-=t; 
				while(t--) c[count++]=0; 
        	}
        	
        	if(b['H'-'A'])//3->5
        	{
        		t=b['H'-'A'];
				for(int k=0;k<arr[3].size();k++) b[arr[3][k]-'A']-=t;
				while(t--) c[count++]=5;  
        	}
        	
        	if(b['F'-'A'])//5->7
        	{
        		t=b['F'-'A'];
				for(int k=0;k<arr[5].size();k++) b[arr[5][k]-'A']-=t; 
				while(t--) c[count++]=7; 
        	}
        	
        	if(b['S'-'A'])//7->9
        	{
        		t=b['S'-'A'];
				for(int k=0;k<arr[7].size();k++) b[arr[7][k]-'A']-=t; 
				while(t--) c[count++]=9; 
        	}
        	
        	if(b['O'-'A'])//1->3
        	{
        		t=b['O'-'A'];
				for(int k=0;k<arr[1].size();k++) b[arr[1][k]-'A']-=t; 
				while(t--) c[count++]=3; 
        	}
        	
        	if(b['I'-'A'])//9->1
        	{
        		t=b['I'-'A'];
				for(int k=0;k<arr[9].size();k++) b[arr[9][k]-'A']-=t; 
				while(t--) c[count++]=1; 
        	}
        	sort(c,c+count);
        	for(int k=0;k<count;k++) cout<<c[k];
        	cout<<endl;
        }
	}
	return 0;
} 
