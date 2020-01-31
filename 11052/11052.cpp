#include <cstdio>
#include <algorithm>
using namespace std;

int N, input;
int cards[1002];
int dp[1002][1002];
int max_val;

int main(void) {
    scanf("%d", &N);

    cards[0] = 0;
    for (int i=1; i<=N; i++) {
        scanf("%d", &input);
        cards[i] = input;
    }
    
    for (int i=1; i<=N; i++) {
        dp[i][i] = cards[i];
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            if (i-j<j) {
                dp[i][j] = max(cards[j]+dp[i-j][i-j], dp[i][j-1]);
            } else {
                dp[i][j] = max(cards[j]+dp[i-j][j], dp[i][j-1]);
            }
        }
    }

    max_val = 0;
    for (int i=1; i<=N; i++) {
        if (max_val<=dp[N][i]) {
            max_val = dp[N][i];
        }
    }

    printf("%d\n", max_val);
    return 0;
}