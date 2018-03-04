#include <iostream>
#include <map>
#include <string>
using namespace std;
struct node {
    string str;
    int num;
};
int main() {
    int n;
    cin >> n;
    map<int, node> m;
    for (int i = 0; i < n; i++) {
        node node1;
        int key;
        cin >> node1.str >> key >> node1.num;
        m[key] = node1;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int buff;
        cin >> buff;
        cout << m[buff].str << " " << m[buff].num << endl;
    }
    return 0;
}
