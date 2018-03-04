//
// Created by Noble on 25/01/2018.
//
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int v;
    int next;
};
node m[100002];
int main() {
    int first, n, interval;
    cin >> first >> n >> interval;
    if (first < 0 || n <= 0 || interval <= 0)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        node nod;
        int addr;
        cin >> addr >> nod.v >> nod.next;
        m[addr] = nod;
    }
    int last = -1;
    int top;
    for (int i = 0; 1; i = 1) {
        vector<int> L(interval);
        if (first == -1)
            break;
        L[0] = first;
        int break_flag = 0;
        for (int i = 1; i < interval; i++) {
            if (m[L[i - 1]].next != -1 || i == interval - 1)
                L[i] = m[L[i - 1]].next;
            else {
                break_flag = 1;
                break;
            }
        }
        if (break_flag == 1) {
            break;
        }
        first = m[L[interval - 1]].next;
        reverse(L.begin(), L.end());
        for (int i = 0; i < interval - 1; i++) {
            m[L[i]].next = L[i + 1];
        }
        m[L[interval - 1]].next = first;
        if (i == 1) {
            m[last].next = L[0];
        } else {
            top = L[0];
        }
        if (first == -1)
            m[L[interval - 1]].next = -1;
        last = L[interval - 1];
    }
    while (1) {
        if (m[top].next != -1)
            printf("%05d %d %05d\n", top, m[top].v, m[top].next);
        else
            printf("%05d %d %d\n", top, m[top].v, m[top].next);
        if (m[top].next == -1)
            break;
        top = m[top].next;
    }
    return 0;
}