#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int h,m;
    char buff;
    scanf("%d:%d",&h,&m);
    if((h>=0&&h<=11)||(h==12&&m==0))
    {
        printf("Only %02d:%02d.  Too early to Dang.",h,m);
    }
    else
    {
        int temp = h-12;
        if(m!=0)
            temp++;
        for(int i =0;i<temp;i++)
            cout<<"Dang";
    }
    return 0;
}