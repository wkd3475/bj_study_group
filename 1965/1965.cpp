#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1001];
int box[1001];

int main(void) {
    int n, input;
    int maxValue=0;
    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        scanf("%d", &box[i]);
        for (int j=1; j<i; j++) {
            if (box[i] > box[j]) {
                dp[i] = max(dp[j], dp[i]);
            }
        }
        dp[i]++;
        maxValue = max(maxValue, dp[i]);
    }
    
    printf("%d", maxValue);

    return 0;
}