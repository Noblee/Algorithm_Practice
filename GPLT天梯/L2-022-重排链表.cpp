#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;
struct Node {
    int address, value, next;
};
Node data[100000];

int main() {
    int start, n;
    cin >> start >> n;

    for (int i = 0; i < n; i++) {
        int buffz;
        cin >> buffz;
        data[buffz].address = buffz;
        cin >> data[buffz].value >> data[buffz].next;
    }
    vector<Node> buffa;
    int p = start;
    if (start < 0 || n <= 0) {
        // printf("-1\n");
        return 0;
    }
    while (1) {
        buffa.push_back(data[p]);
        if (data[p].next == -1) {
            break;
        }
        p = data[p].next;
    }
    int i = 0, j = buffa.size() - 1;
    vector<Node> ans;
    if (i == j)
        ans.push_back(buffa[j]);
    else
        while (1) {
            ans.push_back(buffa[j--]);
            ans.push_back(buffa[i++]);
            if (i == j) {
                ans.push_back(buffa[j]);
                break;
            }
            if (i > j)
                break;
        }
    for (int i = 0; i < ans.size() - 1; i++) {
        printf("%05d %d %05d\n", ans[i].address, ans[i].value, ans[i + 1].address);
    }
    printf("%05d %d %d\n", ans[ans.size() - 1].address, ans[ans.size() - 1].value, -1);
    return 0;
}