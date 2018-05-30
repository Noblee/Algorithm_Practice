#include <iostream>
#include <algorithm>
// 给定长度为n的整数序列，a[1...n], 求[1,n]某个子区间[i , j]
// 使得a[i]+…+a[j]和最大.或者求出最大的这个和.例如(-2,11,-4,13,-5,2)
// 的最大子段和为20,所求子区间为[2,4].
//思路：
//最优子结构：
using namespace std;
int func(int a[], int num) {
    int dp[1000] = {0};
    int maxx = 0;
    for (int i = 1; i < num; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        maxx = dp[i] > maxx ? dp[i] : maxx;
    }
    return maxx;
}

int main() {
    int a[] = {-2, 11, -4, 13, -5, 2};
    cout << func(a, 6);
    return 0;
}