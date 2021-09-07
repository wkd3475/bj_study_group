#include <cstdio>
using namespace std;

#define DIV_VALUE 1000000

int dp[1001][2][3];

int main(void) {
    int n, result;
    scanf("%d", &n);

    dp[1][0][0]=dp[1][1][0]=dp[1][0][1]=1;

    for (int i=2; i<=n; i++) {
        dp[i][0][0] = (dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2])%DIV_VALUE;
        dp[i][0][1] = dp[i-1][0][0]%DIV_VALUE;
        dp[i][0][2] = dp[i-1][0][1]%DIV_VALUE;
        dp[i][1][0] = (dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2]+dp[i-1][1][0]+dp[i-1][1][1]+dp[i-1][1][2])%DIV_VALUE;
        dp[i][1][1] = dp[i-1][1][0]%DIV_VALUE;
        dp[i][1][2] = dp[i-1][1][1]%DIV_VALUE;
    }

    result = (dp[n][0][0]+dp[n][0][1]+dp[n][0][2]+dp[n][1][0]+dp[n][1][1]+dp[n][1][2])%DIV_VALUE;

    printf("%d", result);

    return 0;
}