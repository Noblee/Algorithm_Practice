#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
struct Node {
    double v, w;
    double vperw;
};
vector<Node> yue;

bool compare(const Node &a, const Node &b) {
    return a.vperw > b.vperw; //升序排列，如果改为return a>b，则为降序
    //大降小升
}

int main() {
    double n, d;
    cin >> n >> d;
    yue.resize(n);
    if (n == 0 || d == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> yue[i].w;
    }
    for (int i = 0; i < n; i++) {
        cin >> yue[i].v;
        yue[i].vperw = yue[i].v / yue[i].w;
    }
    sort(yue.begin(), yue.end(), compare);
    double bag = 0;
    int i = 0;
    double value = 0;
    while (1) {
        if (i == n)
            break;
        if (yue[i].w < d - bag) {
            bag += yue[i].w;
            value += yue[i].v;
        } else {
            value += (d - bag) * yue[i].vperw;
            break;
        }
        i++;
    }
    printf("%.2lf", value);
}