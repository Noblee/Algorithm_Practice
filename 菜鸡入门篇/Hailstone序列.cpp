#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

void recursion(int num) {
    if (num <= 1) {
        v.push_back(1);
        return;
    } else if (num % 2 == 0) {
        v.push_back(num);
        recursion(num / 2);
        return;
    } else {
        v.push_back(num);
        recursion(3 * num + 1);
        return;
    }
}

int main() {
    int buff;
    cin >> buff;
    recursion(buff);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i]<<endl;
    }
    return 0;
}