#include "iostream"

using namespace std;
/*
3
1 10 5 20
样例输出
150
数据规模和约定
　　1<=n<=1000, 1<=ai<=10000。
*/
#define inf 0x3f3f3f3f3f3f3f3f
long long int data[1009];
long long int dp[1009][1009];

 int main() {
    long long int n;
    cin >> n;
    n = n + 1;
    for (long long int i = 1; i <= n; i++) {
        cin >> data[i];
    }
    for (long long int i = 1; i <= n; i++)
        for (long long int j = i + 1; j <= n; j++) {
            //if()
            dp[i][j] = inf;
        }
    for (long long int j = 3; j <= n; j++) {
        for (long long int i = j - 2; i >= 1; i--) {
            if (i == j - 2)
                dp[i][j] = data[i] * data[i + 1] * data[j];
            else {
                dp[i][j] = min(dp[i][j],
                               dp[i][i] + dp[i + 1][j] + data[i] * data[i + 1] * data[j]);
                dp[i][j] = min(dp[i][j],
                               dp[i][j - 1] + dp[j][j] + data[i] * data[j - 1] * data[j]);
                for (long long int k = i + 2; k < j - 1; k++) {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[k][j] + data[i] * data[k] * data[j]);
                }
            }
        }
    }
    cout << dp[1][n];
    return 0;
}