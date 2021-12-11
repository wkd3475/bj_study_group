#include <cstdio>

int dp[1001][10];

int main(void) {
    int N, result=0;
    scanf("%d", &N);

    for (int i=0; i<=9; i++) {
        dp[1][i] = 1;
    }

    for (int i=2; i<=N; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=j; k<=9; k++) {
                dp[i][j] = (dp[i][j]+dp[i-1][k]) % 10007;
            }
        }
    }

    for (int i=0; i<=9; i++) {
        result = (result+dp[N][i]) % 10007;
    }

    printf("%d", result);

    return 0;
}