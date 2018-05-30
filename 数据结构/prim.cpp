#include <iostream>
#include <vector>
using namespace std;
int m[1000][1000]
#define inf 0x3f3f3f3f
#define black 1
#define white 0
int p[10000], d[10000], color[10000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; i < n; j++)
            cin >> m[i][j];
    for (int i = 0; i < n; i++) {
        d[i] = inf;
        color[i] = white;
    }
    d[0] = 0;
    p[0] = -1;
    while (1) {
        for (int i = 0; i < n; i++ ) {
            int u = 0;
            int mincost = inf;
            if (color[i] == white && d[i] < mincost) {
                mincost = d[i];
                u = i;
            }
            if (mincost == inf)
                break;
            color[u] = black;
            for (int v = 0; i < n; i++) {
                if (color[v] != black && m[v][u] != -1 && d[v] > m[v][u]) {
                    p[v] = u;
                    d[v] = m[v][u];
                }
            }
        }
    }
    return 0;
}