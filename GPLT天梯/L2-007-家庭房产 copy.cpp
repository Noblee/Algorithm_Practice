#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

struct Node {
    int fu=-1, mu=-1;
    vector<int> haizi;
    int fangnum=0;
    int total_size=0;
    int search = 0;
};
struct ans {
    int minnum=0, p_num=0;
    double r_num=0, size=0;
};
//ans as;
int color=0;
Node data[10001];
int n;
vector<ans> jia;
void dfs(int num,int color,ans &as)
{
    if(num==-1)
        return;
    if(data[num].search==0) {
        as.minnum = min(as.minnum, num);
        data[num].search= color;
        as.p_num++;
        as.r_num+=data[num].fangnum;
        as.size+=data[num].total_size;
        if(data[num].fu!=-1)
            dfs(data[num].fu,color,as);
        if(data[num].mu!=-1)
            dfs(data[num].mu,color,as);
        for(int i =0;i<data[num].haizi.size();i++)
        {
            dfs(data[num].haizi[i],color,as);
        }
    }

}
bool compare(ans &a,ans &b)
{
    if(a.size/a.p_num-b.size/b.p_num>0.0001)
    return a.size/a.p_num>b.size/b.p_num;
    else
        return a.minnum<b.minnum;
}
int main() {

    cin >> n;
    vector<int> renmen;
    for (int i = 0; i < n; i++) {
        int ren, num;
        cin >> ren;
        renmen.push_back(ren);
        cin >> data[ren].fu >> data[ren].mu >> num;
        if(data[ren].fu!=-1)
        data[data[ren].fu].haizi.push_back(ren);
        if(data[ren].mu!=-1)
        data[data[ren].mu].haizi.push_back(ren);
        for (int i = 0; i < num; i++) {
            int buff;
            cin >> buff;
            data[ren].haizi.push_back(buff);
            data[buff].haizi.push_back(ren);
        }
        cin >> data[ren].fangnum >> data[ren].total_size;
    }

    for(int i=0;i<renmen.size();i++) {
        if(data[renmen[i]].search==0)
        {
            ans a_ans;
            a_ans.minnum=renmen[i];
            dfs(renmen[i], ++color, a_ans);
            jia.push_back(a_ans);

        }

    }
    cout<<jia.size()<<endl;
    sort(jia.begin(),jia.end(),compare);
    for(int i=0;i<jia.size();i++)
    {
        printf("%04d %d %.3lf %.3lf\n",
               jia[i].minnum,jia[i].p_num
        ,jia[i].r_num/jia[i].p_num,
               jia[i].size/jia[i].p_num);
    }
}

