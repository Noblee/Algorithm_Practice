#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int N,i;
    cin>>N;
    int a[1002];//书号
    int time[1002]={0};//记录不同编号图书借阅时间 
	bool flag[1002];//书号标志位 
	for(i=0;i<N;i++)
	{
	   int num=-1;//标志位
	   int count=0;//书籍借阅次数 
	   int sum=0;//书籍借阅总时间 
	   int h,m;//小时与分钟 
	   char c;//'S'(借书） or 'E'（还书）
	   memset(flag,false,sizeof(flag)); 
	   memset(time,0,sizeof(time)); 
	   while(num!=0)
	   {	   
		scanf("%d %c %d:%d",&num,&c,&h,&m); 
	   	if(num==0) break;
		else if(c=='S')
	   	{
	   		flag[num]=true;
	   		time[num]=h*60+m; 	   		
	   	}
	   	else if(c=='E')
	   	{
	   		if(flag[num]) 
			   {
			   	sum+=h*60+m-time[num];
			   	count++;
			   }
			flag[num]=false;
			time[num]=0; 
	   	}
	   }
	   int ave;//平均每天图书借阅时间 
	   if(count!=0) ave=sum*1.0/count+0.5;
	   else ave=0; 
	   cout<<count<<' '<<ave<<endl;	
	} 
	return 0;
}
