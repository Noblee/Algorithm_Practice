#include <iostream>
#include <cstring>
using namespace std;
int a[10002];//ÿ��ľ׮��������� 
int count[10002];//��ʾ��������iľ׮ʱ����Ҫ����С��Ծ�� 
bool flag[10002];//��ʾ�����Ƿ���������ľ׮ 

int main()
{
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	memset(count,0,sizeof(count));
	memset(flag,false,sizeof(flag));
	count[1]=0;//��ʼ��
	flag[1]=true;
	//ִ�е�ѭ������Խ�٣�flag��־λ���ȴﵽtrue���ͱ�ʾ�����Ҫ�ﵽ�԰�����С��Ծ�� 
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=a[i]+i;j++)
		{
			if(flag[i] && !flag[j])
			{
				count[j]=count[i]+1;
				flag[j]=true;
			}
		}
	}
	if(flag[n+1]) cout<<count[n+1];
	else cout<<-1; 
	return 0;
}
