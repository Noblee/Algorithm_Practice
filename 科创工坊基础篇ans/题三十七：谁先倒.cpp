#include <iostream>

using namespace std;
int a1[100];//�׺�
int a2[100];//�׻�
int b1[100];//�Һ�
int b2[100];//�һ� 
int main()
{
	int M1,M2,N,i=0;
	cin>>M1>>M2;//����������˵������� 
	cin>>N;//����������˻�ȭ����
	int t1=0,t2=0;//t1,t2�ֱ��ʾ�������˺ȾƵ���
	int n=N; 
	while(n--) cin>>a1[i++]>>a2[i]>>b1[i]>>b2[i];
	i=0;
	while(N--)
	{
		if(a2[i]==a1[i]+b1[i]) 
	    {
	   	  if(a2[i]!=b2[i])
	   	  {
	   	  M1--;
	   	  t1++; 
	   	  }
	     }
	     
	   if(b2[i]==a1[i]+b1[i])
	     {
	      if(a2[i]!=b2[i])
	   	  {
	   	  M2--;
	   	  t2++; 
	   	  }
	     }
	     
	  if(M1==-1)
	   	  {
	   	  	cout<<'A'<<endl<<t2;
	   	  	break;
	   	  }
	   	  
	  if(M2==-1)
	   	  {
	   	  	cout<<'B'<<endl<<t1;
	   	  	break;
	   	  }
	   i++;	
	} 
	return 0;
} 
