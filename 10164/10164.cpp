#include <cstdio>

int dp[16][16];

int main(void) {
    int N, M, K;
    int col=1, row=1;
    scanf("%d %d %d", &N, &M, &K);

    dp[1][1] = 1;

    if (K!=0) {
        col = (K-1)%M + 1;
        row = (K-1)/M + 1;

        for (int i=1; i<=col; i++) {
            for (int j=1; j<=row; j++) {
                if (i==1 && j==1)
                    continue;
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }

    for (int i=col; i<=M; i++) {
        for (int j=row; j<=N; j++) {
            if (i==col && j==row)
                continue;
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }

    printf("%d", dp[M][N]);

    return 0;
}