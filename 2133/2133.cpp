#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int dp[31];

int main(void) {
    scanf("%d", &N);
    if (N%2 != 0) {
        printf("0");
        return 0;
    }

    dp[0] = 1;
    dp[2] = 3;

    for (int i=4; i<=N; i+=2) {
        dp[i] = dp[i-2]*3;
        for (int j=2; i-2*j>=0; j++) 
            dp[i] += dp[i-2*j] * 2;
    }

    printf("%d", dp[N]);
    return 0;
}