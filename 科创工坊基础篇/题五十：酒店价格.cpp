#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//����һ���ṹ���������۸��������ʼ���ڣ����������Լ�����۸� 
struct Hotel
{
	int begin;
	int end;
	int price;
};

//�ȽϺ�������С������ 
bool cmp(Hotel a,Hotel b)
{
	return a.begin<b.begin;
}

int main()
{
    Hotel a[400];//�������۸�������������400����һ��365��Ϊ��׼
    int i=0;
    bool flag=true;
	while(1)
	{
	    cin>>a[i].begin>>a[i].end>>a[i].price;
		if(a[i].begin==0 && a[i].end==0 && a[i].price==0) break;
		else i++;
	} 
	int n=i;
	sort(a,a+n,cmp);//���ռ۸��������ʼ���ڴ�С��������
	int B=a[0].begin;
    int E=a[0].end;
	for(i=0;i<n;i++)
	{
		if(a[i].end>=a[i+1].begin-1 && a[i].price==a[i+1].price)
		{
			E=a[i+1].end;   
			continue;      
		}
		if(a[i].end==a[i+1].begin && a[i].price!=a[i+1].price) 
		{
		  if(B==E) B=E=E-1;
		  else E=E-1;

		}
		if(flag) 
			{
				cout<<'['<<B<<','<<E<<','<<a[i].price<<']';
				flag=false;
			}
		else cout<<','<<'['<<B<<','<<E<<','<<a[i].price<<']';
		B=a[i+1].begin;
		E=a[i+1].end;
	}
	return 0;
}
