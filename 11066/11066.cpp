#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int arr[501];
int dp[501][501];
int sum[501];

int getValue(int start, int end);

int main() {
    int T, K;
    scanf("%d", &T);

    sum[0] = 0;

    while (T--) {
        scanf("%d", &K);
        for (int i=1; i<=K; i++) {
            scanf("%d", &arr[i]);
            sum[i] = sum[i-1] + arr[i];

            for (int j=1; j<=K; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        printf("%d\n", getValue(1, K));
    }

    return 0;
}

int getValue(int start, int end) {
    if (start >= end) {
        return 0;
    }

    if (start == end-1) {
        return arr[start] + arr[end];
    }

    if (dp[start][end] < INT_MAX) {
        return dp[start][end];
    }

    for (int i=start; i<end; i++) {
        dp[start][end] = min(dp[start][end], getValue(start, i)+getValue(i+1, end)+sum[end]-sum[start-1]);
    }
    return dp[start][end];
}