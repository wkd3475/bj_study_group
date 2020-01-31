#include <cstdio>

int dp[1000001][32];

int main(void) {
    int N;
    scanf("%d", &N);

    dp[1][0] = 1;

    for (int i=2; i<=N; i++) {
        for (int k=0; (1<<k)<=i; k++) {
            if ((1<<k) == i) {
                dp[i][k] = 1;
            } else {
                for (int j=0; j<=k; j++) {
                    dp[i][k] = (dp[i][k] + dp[i-(1<<k)][j])%1000000000;
                }
            }
        }
    }

    int result = 0;
    for (int i=0; (1<<i)<=N; i++) {
        result = (result + dp[N][i])%1000000000;
    }

    printf("%d\n", result);
    return 0;
}