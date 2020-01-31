#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int times[22];
int moneys[22];
int dp[22];

int main(void) {
    scanf("%d", &N);
    for (int i=1 ;i<=N; i++) {
        scanf("%d %d", &times[i], &moneys[i]);
    }

    for (int i=N; i>0; i--) {
        if (times[i]+i-1<=N) {
            dp[i] = max(moneys[i]+dp[i+times[i]], dp[i+1]);
        } else {
            dp[i] = dp[i+1];
        }
    }

    printf("%d\n", dp[1]);
    return 0;
}