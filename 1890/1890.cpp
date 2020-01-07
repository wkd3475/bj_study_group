#include <cstdio>

int main() {
    int N;
    int inputs[101][101];
    long dp[101][101]={0,};
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &inputs[i][j]);
        }
    }

    dp[N-1][N-1]=1;

    for (int i=N-1; i>=0; i--) {
        for (int j=N-1; j>=0; j--) {
            if (i==N-1&&j==N-1)
                continue;

            if (inputs[i][j]+i<N)
                dp[i][j]+=dp[i+inputs[i][j]][j];
            
            if (inputs[i][j]+j<N)
                dp[i][j]+=dp[i][j+inputs[i][j]];
        }
    }

    printf("%ld\n", dp[0][0]);
    return 0;
}