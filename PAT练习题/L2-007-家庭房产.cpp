#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

struct Node {
    int fu, mu;
    vector<int> haizi;
    int fangnum;
    int total_size;
    bool search = false;
};
struct ans {
    int minnum, p_num;
    double r_num, size;
};
ans as;
vector <ans> jiating;
map<int, Node> m;
int n;
void dfs(map<int, Node>::iterator it);
int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int buff, num;
        Node nd;
        cin >> buff;
        cin >> nd.fu >> nd.mu >> num;
        for (int i = 0; i < num; i++) {
            int buff;
            cin >> buff;
            nd.haizi.push_back(buff);
        }
        cin >> nd.fangnum >> nd.total_size;
        m[buff] = nd;
    }
    map<int, Node>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second.search == false) {
            as = {0x7fffffff, 0, 0, 0};
            dfs(it);
            jiating.push_back(as);
        }
    }
    cout<<jiating.size()<<endl;

    for(int i=0;i<jiating.size();i++)
    {
        printf("%04d %d %.3lf %.3lf\n",
               jiating[i].minnum,jiating[i].p_num
        ,jiating[i].p_num/jiating[i].r_num,
               jiating[i].size/jiating[i].p_num);
    }
}

void dfs(map<int, Node>::iterator  it) {

    Node &nd = it->second;
    if(nd.search==true)
        return;0
    as.p_num++;
    nd.search = true;
    as.size += nd.total_size;
    as.r_num += nd.fangnum;
    if (as.minnum > it->first)
        as.minnum = it->first;
    if (m.find(nd.mu)!=m.end())
        dfs(m.find(nd.mu));
    if (m.find(nd.fu)!=m.end())
        dfs(m.find(nd.fu));
    for (int i = 0; i < nd.haizi.size(); i++) {
        if (m.find(nd.haizi[i])!=m.end())
        dfs(m.find(nd.haizi[i]));
    }

}