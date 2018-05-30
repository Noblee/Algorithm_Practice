#include "iostream"

using namespace std;
/*问题描述
　　在一条直线上有n堆石子，每堆有一定的数量，每次可以将两堆相邻的石子合并，合并后放在两堆的中间位置，合并的费用为两堆石子的总数。求把所有石子合并成一堆的最小花费。
输入格式
　　输入第一行包含一个整数n，表示石子的堆数。
　　接下来一行，包含n个整数，按顺序给出每堆石子的大小 。
输出格式
　　输出一个整数，表示合并的最小花费。
样例输入
5
1 2 3 4 5
样例输出
33
数据规模和约定
　　1<=n<=1000, 每堆石子至少1颗，最多10000颗。*/
#define inf 0x3f3f3f3f
int dp[1005][1005];
int data[1005];
int summ[1005];
int sum(int a,int b)
{
    return summ[b]-summ[a-1];
}
int main() {
    int n;
    cin >> n;
    memset(dp,inf,sizeof(dp));


    for (int i = 1; i <= n; i++) {
        cin >> data[i];
        dp[i][i]=data[i];
    }
    for(int i =1;i<=n;i++) {
        summ[i]=summ[i-1]+data[i];
    }

    for (int j = 2; j <= n; j++)
        for (int i = j - 1; i >= 1; i--) {
            if (i == j - 1)
                dp[i][j] = data[i] + data[j];
            else {
                for (int k = i ; k <= j - 1; k++) {
                    if(k!=i&&k!=j-1)
                    dp[i][j] = min(dp[i][j], (dp[i][k] + dp[k + 1][j] + sum(i, j)));
                    else if(k==i)
                        dp[i][j] = min(dp[i][j], (dp[i][i] + dp[i + 1][j] + sum(i+1, j)));
                    else
                        dp[i][j] = min(dp[i][j], (dp[i][j-1] + dp[j][j] + sum(i, j-1)));
                }
            }
        }
    cout << dp[1][n];
    return 0;
}