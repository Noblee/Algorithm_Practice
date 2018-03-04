#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
struct Node
{
    int key;
    int next;
} aa[maxn];
int main()
{
    int fadd,n;
    cin>>fadd>>n;
    int vis[maxn]= {0},ans[maxn],res[maxn];
    int t1=0,t2=0;
    int add;
    for(int i=0; i<n; i++)
    {
        cin>>add;
        cin>>aa[add].key>>aa[add].next;
    }
    for(int i=fadd; i!=-1; i=aa[i].next)
    {
        int num=abs(aa[i].key);
        if(!vis[num])
            vis[num]=1,ans[t1++]=i;
        else
            res[t2++]=i;
    }
    printf("%05d %d ",ans[0],aa[ans[0]].key);
    for(int i=1; i<t1; i++)
    {
        printf("%05d\n",ans[i]);
        printf("%05d %d ",ans[i],aa[ans[i]].key);
    }
    printf("-1\n");
    if(t2)
    {
        printf("%05d %d ",res[0],aa[res[0]].key);
        for(int i=1; i<t2; i++)
        {
            printf("%05d\n",res[i]);
            printf("%05d %d ",res[i],aa[res[i]].key);
        }
        printf("-1\n");
    }
    return 0;
}