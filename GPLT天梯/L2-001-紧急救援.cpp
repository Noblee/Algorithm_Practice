//
// Created by Noble on 05/03/2018.
//
#include <iostream>
#include <vector>

#define  inf 0x3f3f3f3f
#define  black 1
int adj[550][550];
int p_num[550];
int dis[550], color[550] = {0};
using namespace std;
vector<int> p[550];
int cc = 0;
vector<int> route;
vector<int> you_route;
long long maxx=0;
void dfs(int visit) {
    route.push_back(visit);
    if (p[visit].size() == 0) {
        cc++;
        long long buff=0;
        for(int i =0;i<route.size();i++)
        {
            buff+=p_num[route[i]];
        }
        if(buff>maxx)
        {
            maxx=buff;
            you_route=route;
        }
    }
    for (int i = 0; i < p[visit].size(); i++) {

        dfs(p[visit][i]);
    }
    route.pop_back();
}

int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++) {
        cin >> p_num[i];
        dis[i] = inf;
    }
    dis[s] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    int lastvisit = -1;
    while (1) {
        int mincost = inf;
        int tovisit = -1;
        for (int i = 0; i < n; i++) {
            if (dis[i] != inf && color[i] != black && mincost > dis[i]) {
                mincost = dis[i];
                tovisit = i;
            }
        }
        if (tovisit == -1)
            break;
        color[tovisit] = black;
        lastvisit = tovisit;
        for (int v = 0; v < n; v++) {
            if (adj[tovisit][v] != 0 && color[v] != black) {
                if (dis[tovisit] + adj[tovisit][v] < dis[v]) {
                    dis[v] = dis[tovisit] + adj[tovisit][v];
                    p[v].clear();
                    p[v].push_back(tovisit);
                } else if ((dis[tovisit] + adj[tovisit][v]) == dis[v]) {
                    p[v].push_back(tovisit);
                }
            }
        }
    }
    dfs(lastvisit);
    cout<<cc<<" "<<maxx<<endl;
    for(int i =you_route.size()-1;i>0;i--)
        cout<<you_route[i]<<" ";
    cout<<you_route[0];
    return 0;
}