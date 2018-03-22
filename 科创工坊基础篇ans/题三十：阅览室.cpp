#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int N,i;
    cin>>N;
    int a[1002];//���
    int time[1002]={0};//��¼��ͬ���ͼ�����ʱ�� 
	bool flag[1002];//��ű�־λ 
	for(i=0;i<N;i++)
	{
	   int num=-1;//��־λ
	   int count=0;//�鼮���Ĵ��� 
	   int sum=0;//�鼮������ʱ�� 
	   int h,m;//Сʱ����� 
	   char c;//'S'(���飩 or 'E'�����飩
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
	   int ave;//ƽ��ÿ��ͼ�����ʱ�� 
	   if(count!=0) ave=sum*1.0/count+0.5;
	   else ave=0; 
	   cout<<count<<' '<<ave<<endl;	
	} 
	return 0;
}
