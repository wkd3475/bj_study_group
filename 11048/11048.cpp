#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int input;
int dp[1001][1001];

int main(void) {
    scanf("%d %d", &N, &M);

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            scanf("%d", &input);
            dp[i][j] = input;
            if (i-1 > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]+input);
            }

            if (j-1 > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j-1]+input);
            }

            if (i-1 > 0 && j-1 > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+input);
            }
        }
    }

    printf("%d", dp[N][M]);

    return 0;
}