#include <iostream>
#include <vector>
#include <queue>
//题目:
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
//Summary
//BFS的应用，求从某一节点开始到达所有节点的最短路径。（最少步数）
//BFS通过单向队列来实现
//一般认为是连通图。
using namespace std;
#define white 0
#define black 2
int times = 0;
int n;
vector<int> color, kaishi, jieshu;
vector<vector<int>> m;
void visit() {}
int main() {
    cin >> n;
    color.resize(n + 1, 0);
    kaishi.resize(n + 1, 0);
    jieshu.resize(n + 1, 0);
    vector<int> distance(n + 1, 0);
    m.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        int x, num;
        cin >> x >> num;
        for (int j = 0; j < num; j++) {
            int y;
            cin >> y;
            m[x][y] = 1;
        }
    }
    queue<int> q;
    q.push(1);
    color[1] = black;
    while (q.empty() != 1) {
        int buff = q.front();
        q.pop();
        ++times;
        for (int j = 1; j < n + 1; j++) {
            if (m[buff][j] == 1) {
                if (color[j] != black) {
                    kaishi[j] = times;
                    color[j] = black;
                    visit();
                    distance[j] = distance[buff] + 1;
                    q.push(j);
                }
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        if (distance[i] != 0 || i == 1)
            cout << i << " " << distance[i] << endl;
        else
            cout << i << " " << -1 << endl;

    }
    return 0;
}

