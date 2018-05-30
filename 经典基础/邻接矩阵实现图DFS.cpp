#include <iostream>
#include <vector>
//题目:
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B
//Summary
//图的DFS总的还说是一个有记忆的DFS，通过访问过的节点加颜色来区别三种状态
//白色未访问过，灰色访问过但可能有通往白色节点的边，黑色为边和节点都访问过。
//但其实只需要标记白色和黑色来区分某个节点是否被访问过就可以了
//在访问时标记灰色，一层DFS结束后标记为黑色
//某一个节点不一定能够DFS所有节点（多个连通分量）
//所以要对每一个节点做DFS
using namespace std;
#define white 0
#define grey 1
#define black 2
int times = 0;
int n;
vector<int> color, kaishi, jieshu;
vector<vector<int>> m;
void dfs(int num);
void visit(int num){}
int main() {
    cin >> n;
    color.resize(n + 1, 0);
    kaishi.resize(n + 1, 0);
    jieshu.resize(n + 1, 0);
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
    for (int i = 1; i < n + 1; i++)
        if (color[i] != black)
            dfs(i);
    for (int i = 1; i < n + 1; i++) {
        cout << i << " " << kaishi[i] << " " << jieshu[i] << endl;
    }
    return 0;
}
void dfs(int num) {
    color[num] = grey;
    kaishi[num] = ++times;
    visit(num);
    for (int i = 1; i < n + 1; i++) {
        if (m[num][i] == 1 && color[i] == white)
            dfs(i);
    }
    color[num] = black;
    jieshu[num] = ++times;
}