#include <cstdio>
#include <algorithm>
using namespace std;

int N, input, max_container;
int containers[50001];
int sumDp[50001];
int DP[50001][3];

int solve(int rest, int start) {
    if (rest == 0) {
        return 0;
    }
    int maxValue = 0;
    for (int i=start; i+max_container-1<=N-(rest-1)*max_container; i++) {
        int sumValue = 0;
        if (sumDp[i]!=0) {
            sumValue = sumDp[i];
        } else {
            for (int j=0; j<max_container; j++) {
                sumValue += containers[i+j];
                sumDp[i] = sumValue;
            }
        }

        if (DP[i+max_container][rest-2]==0) {
            DP[i][rest-1] = max(sumValue + solve(rest-2, i+max_container), DP[i][rest-1]);
        } else {
            DP[i][rest-1] = max(sumValue + DP[i+max_container][rest-2], DP[i][rest-1]);
        }
        
       
        if (maxValue<DP[i][rest-1]) {
            maxValue = DP[i][rest-1];
        }
    }
    return maxValue;
}

int main(void) {
    scanf("%d", &N);

    for (int i=1; i<=N; i++) {
        scanf("%d", &input);
        containers[i] = input;
    }

    scanf("%d", &max_container);



    printf("%d", solve(3, 0));

    return 0;
}