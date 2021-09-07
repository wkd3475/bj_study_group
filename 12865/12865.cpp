#include <cstdio>
#include <algorithm>

int dp[101][100001];
int W[101], V[101];

int main(void) {
    int N, K;
    scanf("%d%d", &N, &K);

    for (int i=1; i<=N; i++) {
        scanf("%d%d", &W[i], &V[i]);
        for (int j=1; j<=K; j++) {
            if (j >= W[i])
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-W[i]]+V[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("%d", dp[N][K]);

    return 0;
}