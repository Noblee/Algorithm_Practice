#include<cstdio>
#include<iostream>
using namespace std;

int pre[10005];
int f[10005];
//每个节点的初始节点都是
void init() { for(int i=0;i<10004;i++) pre[i]=i,f[i]=0;}
int fin(int x) { return pre[x]==x?x:pre[x]=fin(pre[x]); }

int main()
{
    init();
    int n,q,k,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        cin>>a;
        f[a]=1;
        for(int j=1;j<k;j++)
        {
            cin>>b;
            f[b]=1;
            int x=fin(a);
            int y=fin(b);
            if(x!=y)
                pre[x]=y;
        }
    }
    int cnt=0,tot=0;
    for(int i=0;i<10004;i++)
    {
        if(f[i]==1)
        {
            cnt++;
            if(pre[i]==i)
                tot++;
        }
    }
    printf("%d %d\n",cnt,tot);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        if(fin(a)==fin(b))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}