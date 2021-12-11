#include <cstdio>

int dp[31][31];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    dp[1][1] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
    printf("%d", dp[n][k]);
    return 0;
}