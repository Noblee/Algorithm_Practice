#include "iostream"
#include <vector>
#include <string>
#include <cmath>

using  namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        int day,h,m;
        cin>>day;
        scanf("%d:%d",&h,&m);
        if(day==0)
            printf("0 %02d:%02d\n",h,m);
        else
        {
            int temp=((day-1)*24*60+h*60+m)/2;
            int dayy,hy,my;
            dayy = temp/(24*60)+1;
            temp = temp%(24*60);
            hy = temp/(60);
            temp = temp%(60);
            my =temp;
            printf("%d %02d:%02d\n",dayy,hy,my);
        }
    }
    return 0;
}
