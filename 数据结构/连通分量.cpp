#include <iostream>
#include <vector>

//题目:
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D
//Summary
//连通分量的原理很简单，对于非连通图生成连通森林，原理就是对每个节点(没有标记颜色的)
//进行DFS，并对搜索到的节点标记id
//using namespace std;
std::vector<int> rela[100002];
int color[100002];
void dfs(int i, int id);
int main() {
    int num, rnum;
    std::cin >> num >> rnum;
    int idd = 1;
    for (int i = 0; i < rnum; i++) {
        int a, b;
        std::cin >> a >> b;
        rela[a].push_back(b);
        rela[b].push_back(a);
    }
    for (int i = 0; i < num; i++) {
        if (color[i] == 0)
            dfs(i, ++idd);
    }
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a>> b;
        if (color[a] == color[b]&&color[a]!=0) {
            std::cout << "yes" << std::endl;
        } else
            std::cout << "no" << std::endl;
    }
    return 0;
}
void dfs(int i, int idd) {
    color[i] = idd;
    for (int ii = 0; ii < rela[i].size(); ii++)
        if (color[rela[i][ii]] == 0) {
            dfs(rela[i][ii], idd);
        }
}