#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Node {
    int num, mo, hongbao;
};

bool compare(Node &a, Node &b) {
    if (a.mo != b.mo)
        return a.mo > b.mo;
    else if (a.hongbao != b.hongbao)
        return a.hongbao > b.hongbao;
    else
        return a.num < b.num;

}

Node data[10005];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        data[i].hongbao = m;
        data[i].num = i;
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            data[a].mo += b;
            data[i].mo -= b;
        }
    }
    sort(data + 1, data + n + 1, compare);
    for (int i = 1; i <= n; i++) {
        printf("%d %.2f\n", data[i].num, data[i].mo / (double) 100);
    }
    return 0;
}