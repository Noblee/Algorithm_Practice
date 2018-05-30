#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int color[504];
int m[504][504];

int main() {
    int V, E, K;
    scanf("%d %d %d", &V, &E, &K);
    for (int i = 0; i < E; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        m[a - 1][b - 1] = 1;
        m[b - 1][a - 1] = 1;
    }
    int buffz;
    scanf("%d", &buffz);
    for (int i = 0; i < buffz; i++) {
        for (int j = 0; j < V; j++) {
            int a;
            scanf("%d", &a);
            color[j] = a;
        }
        int flag = 0;
        for (int ii = 0; ii < V; ii++) {
            for (int jj = ii + 1; jj < V; jj++) {
                if (m[ii][jj] == 1 && color[ii] == color[jj]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        sort(color, color + V);
        int t = (unique(color, color + V) - color);
        if (t != K)flag = 1;
        if (flag == 1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}