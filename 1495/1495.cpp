#include <cstdio>
using namespace std;

int dp[101][1001];

int main(void) {
    int num_music, start, max_volume;
    int input_volume;
    scanf("%d %d %d", &num_music, &start, &max_volume);
    dp[0][start] = 1;

    for (int i=1; i<=num_music; i++) {
        scanf("%d", &input_volume);
        for (int j=0; j<=max_volume; j++) {
            if (dp[i-1][j]) {
                if (j+input_volume <= max_volume) {
                    dp[i][j+input_volume] = 1;
                }
                
                if (j-input_volume >= 0) {
                    dp[i][j-input_volume] = 1;
                }
            }
        }
    }

    for (int i=max_volume; i>=0; i--) {
        if (dp[num_music][i]==1) {
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}