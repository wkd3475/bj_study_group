#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1000001];

int main(void) {
    int x;
    scanf("%d", &x);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i=4; i<=1000000; i++) {
        int a, b, c;
        if (i % 3 == 0) {
            a = dp[i/3]+1;
        } else {
            a = 12345678;
        }
        
        if (i % 2 == 0) {
            b = dp[i/2]+1;
        } else {
            b = 12345678;
        }

        c = dp[i-1] + 1;
        dp[i] = min(a, min(b, c));
    }

    printf("%d", dp[x]);

    return 0;
}