#include <cstdio>

int N, input, max_container;
int containers[50001];
int dp[50001][3];

int main(void) {
    scanf("%d", &N);

    for (int i=1; i<=N; i++) {
        scanf("%d", &input);
        containers[i] = input;
    }

    scanf("%d", &max_container);

    for (int i=1; i<=N-3*max_container+1; i++) {
        max
        
        int val = sumValue + solve(rest-1, i+max_container);
        if (maxValue<val) {
            maxValue = val;
        }
    }

    for (int j=i+max_container; j<=N-2*max_container+1; j++) {
            sumValue += containers[i+j];
    }
    return 0;
}