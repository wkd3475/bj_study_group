#include <cstdio>
#include <utility>
using namespace std;

int inputArray[501][501];
int dp[501][501]={0,};
int visited[501][501]={0,};
int action[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int findWays(int height, int width, int max_h, int max_w) {
    if (visited[height][width]==1)
        return dp[height][width];

    if (height==0&&width==0)
        return 1;
    
    for (int i=0; i<4; i++) {
        if (height+action[i][0]<0||height+action[i][0]>=max_h)
            continue;

        if (width+action[i][1]<0||width+action[i][1]>=max_w)
            continue;

        if (inputArray[height][width] < inputArray[height+action[i][0]][width+action[i][1]]) {
            dp[height][width] += findWays(height+action[i][0], width+action[i][1], max_h, max_w);
        }
    }

    visited[height][width]=1;

    return dp[height][width];
}

int main() {
    int height, width;
    scanf("%d %d", &height, &width);

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            scanf("%d", &inputArray[i][j]);
        }
    }

    for (int i=height-1; i>=0; i--) {
        for (int j=width-1; j>=0; j--) {
            findWays(i, j, height, width);
        }
    }

    printf("%d\n", dp[height-1][width-1]);
    return 0;
}