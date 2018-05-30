#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;
vector<set<int>> list_set;

int main() {
    int n = 0;
    cin >> n;
    list_set.resize(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int buff;
            cin >> buff;
            list_set[i].insert(buff);
        }
    }
    int test_n;
    cin >> test_n;
    set<int>::iterator it;
    vector<double> buff;
    for (int i = 0; i < test_n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int cc = 0;
        for (it = list_set[a].begin(); it != list_set[a].end(); it++) {
            if (list_set[b].find(*it) != list_set[b].end()) {
                cc++;
            }
        }
        buff.push_back((double) cc / (double) (list_set[a].size() + list_set[b].size() - cc));
    }
    for (int i = 0; i < buff.size(); i++) {
        printf("%.2lf", buff[i]*100);
        cout<<'%'<<endl;
    }
}