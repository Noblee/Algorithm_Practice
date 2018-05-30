#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

#include <map>

#include <set>
//10 GAO3 Magi Zha1 Sen1 Quan FaMK LSum Eins FatM LLao
//8
//Magi 50
//Pota 30
//LLao 3
//Ammy 48
//Dave 15
//GAO3 31
//Zoro 1
//Cath 60
using namespace std;

int main() {
    int n, m;
    cin >> n;
    set<string> guanzhu;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        guanzhu.insert(str);
    }
    cin >> m;
    map<string, int> data;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        string str;
        int b;
        cin >> str >> b;
        sum += b;
        data[str] = b;
    }
    double temp;
    if (data.size() != 0)
        temp = static_cast<int>((double) sum / data.size());
    map<string, int>::iterator it;
    int flag = 0;
    for (it = data.begin(); it != data.end(); it++) {
        if (it->second > temp && guanzhu.find(it->first) == guanzhu.end()) {
            cout << it->first << endl;
            flag = 1;
        }
    }
    if (!flag)
        cout << "Bing Mei You";
    return 0;
}