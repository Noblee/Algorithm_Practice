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
        a[c]=1;  //枚举，将所有c字符在a数组中的位置标1 
    }  
    while(s[i]!=0)  
    {  
        if(!a[s[i]])  
        {  
            //输出字符串s中在a数组中为0的字符元素 
			cout<<s[i];
        }  
        i++;  
    }  
    cout<<endl;
    return 0;  
} 
