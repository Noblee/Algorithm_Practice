#include <iostream>
#include <vector>
//Hailstone Sequence问题是一个著名的数学问题，至今没有证明其正确性，
// 也没证明其是错误的，即任何一个正整数N，如果是偶数的话就除以2，
// 如果是奇数的话就乘以3再加上1，最后这个数都会变为1。
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