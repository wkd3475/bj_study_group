#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int row[500];
int col[500];
int dp[500][500];

int main(void) {
    int N;

    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        scanf("%d %d", &row[i], &col[i]);
    }

    for (int dif=1; dif<N; dif++) {
        for (int i=0; i+dif<N; i++) {
            dp[i][i+dif] = INT_MAX;
            for (int mid=i; mid<i+dif; mid++) {
                dp[i][i+dif] = min(dp[i][i+dif], dp[i][mid]+dp[mid+1][i+dif]+row[i]*col[mid]*col[i+dif]);
            }
        }
    }

    printf("%d\n", dp[0][N-1]);
    
    return 0;
}