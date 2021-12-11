#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, input[101];
int dp[10001];

int main(void) {
    scanf("%d %d", &n, &k);

    for (int i=0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    for (int i=0; i<10001; i++) {
            dp[i] = 123456789;
    }

    dp[0] = 0;
    for (int i=1; i<=k; i++) {
        for (int j=0; j<n; j++) {
            if (i-input[j] >= 0)
                dp[i] = min(dp[i], dp[i-input[j]]+1);
        }
    }

    if (dp[k] == 123456789)
        printf("-1");
    else
        printf("%d", dp[k]);

    return 0;
}