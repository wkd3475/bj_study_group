#include <cstdio>
#define RIGHT 0
#define UP 1

int w, h;
int dp[101][101][2][2];

int dfs(int x, int y, int direction, int is_changeable) {
    if (x > w || y > h)
        return 0;

    if (dp[x][y][direction][is_changeable] != 0)
        return dp[x][y][direction][is_changeable];

    if (direction == RIGHT && is_changeable) {
        return dp[x][y][direction][is_changeable] = dfs(x+1, y, RIGHT, true) % 100000 + dfs(x, y+1, UP, false) % 100000;
    } else if (direction == RIGHT && !is_changeable) {
        return dp[x][y][direction][is_changeable] = dfs(x+1, y, RIGHT, true) % 100000;
    } else if (direction == UP && is_changeable) {
        return dp[x][y][direction][is_changeable] = dfs(x+1, y, RIGHT, false) % 100000 + dfs(x, y+1, UP, true) % 100000;
    } else // if (direction == UP && !is_changeable)
        return dp[x][y][direction][is_changeable] = dfs(x, y+1, UP, true) % 100000;
}

int main(void) {
    int result = 0;
    scanf("%d %d", &w, &h);

    dp[w][h][RIGHT][true] = 1;
    dp[w][h][RIGHT][false] = 1;
    dp[w][h][UP][true] = 1;
    dp[w][h][UP][false] = 1;

    dfs(2, 1, RIGHT, true);
    dfs(1, 2, UP, true);
    printf("%d", (dp[2][1][RIGHT][true]+dp[1][2][UP][true]) % 100000);
    return 0;
}

//  start at : 2022-03-13 00:40
// solved at : 2022-03-13 02:43