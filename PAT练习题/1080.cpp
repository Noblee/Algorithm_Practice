#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
struct Node {
    int bc, qz, qm;
    Node() : bc(-1), qz(-1), qm(-1) {}
};
struct ansNode {
    Node n;
    string num;
    int G;
};
bool compare(ansNode a, ansNode b) {
    if (a.G != b.G)
        return a.G > b.G;
    else
        return a.num < b.num;
}
map<string, Node> data;
vector<ansNode> ans;
int main() {
    int p, m, n;
    cin >> p >> m >> n;
    for (int i = 0; i < p; i++) {
        string buff;
        int bc;
        cin >> buff >> bc;
        data[buff].bc = bc;
    }
    for (int i = 0; i < m; i++) {
        string buff;
        int qz;
        cin >> buff >> qz;
        data[buff].qz = qz;
    }
    for (int i = 0; i < n; i++) {
        string buff;
        int qm;
        cin >> buff >> qm;
        data[buff].qm = qm;
    }
    map<string, Node>::iterator it;
    for (it = data.begin(); it != data.end(); it++) {
        int buff = (int) round((double(it->second.qz)) * (double) 0.40 +
                               (double(it->second.qm)) * (double) 0.60);
        if (it->second.qz <= it->second.qm)
            buff = it->second.qm;
        if (buff >= 60 && it->second.bc >= 200) {
            ansNode an;
            an.n = it->second;
            an.num = it->first;
            an.G = buff;
            ans.push_back(an);
        }
    }
    sort(ans.begin(), ans.end(), compare);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].num << " " << ans[i].n.bc << " "
             << ans[i].n.qz << " " << ans[i].n.qm << " "
             << ans[i].G << endl;
    }
    return 0;
}