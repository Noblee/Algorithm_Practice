#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()  
{  
    char s[10001],c;  
    int a[256],i=0;  
    memset(a,0,256*sizeof(int));  
    gets(s);  
    while((c=getchar())!='\n')  
    {  
        a[c]=1;  //ö�٣�������c�ַ���a�����е�λ�ñ�1 
    }  
    while(s[i]!=0)  
    {  
        if(!a[s[i]])  
        {  
            //����ַ���s����a������Ϊ0���ַ�Ԫ�� 
			cout<<s[i];
        }  
        i++;  
    }  
    cout<<endl;
    return 0;  
} 
