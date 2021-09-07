#include <cstdio>

int max_y, max_x;
int ground[52][52];
int layer[52][52];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int total_water;
int isVisited[52][52];
int notNeedFlag = 0;

int dfs(int y, int x, int h) {
    int result = 1;
    isVisited[y][x] = h;
    for (int i=0; i<4; i++) {
        int nextX = x+dx[i];
        int nextY = y+dy[i];
        if (isVisited[nextY][nextX] == h) {
            continue;
        }

        if (layer[nextY][nextX] == 1) {
            continue;
        }

        if (nextX == max_x || nextX == 1) {
            notNeedFlag = 1;
            continue;
        }

        if (nextY == max_y || nextY == 1) {
            notNeedFlag = 1;
            continue;
        }

        result += dfs(nextY, nextX, h);
    }
    return result;
}

void makeLayer(int h) {
    for (int i=1; i<=max_y; i++) {
        for (int j=1; j<=max_x; j++) {
            if (ground[i][j] >= h) {
                layer[i][j] = 1;
            } else {
                layer[i][j] = 0;
            }
        }
    }
}

int getAmount(int h) {
    int amount = 0;
    for (int i=2; i<max_y; i++) {
        for (int j=2; j<max_x; j++) {
            notNeedFlag = 0;
            if (isVisited[i][j]!=h && layer[i][j]==0) {
                int temp = dfs(i, j, h);
                if (!notNeedFlag) {
                    amount += temp;
                }
            }
        }
    }
    return amount;
}

int main(void) {
    int max_h = 0;
    scanf("%d %d", &max_y, &max_x);
    
    for (int i=1; i<=max_y; i++) {
        for (int j=1; j<=max_x; j++) {
            scanf("%1d", &ground[i][j]);
            if (max_h < ground[i][j])
                max_h = ground[i][j];
        }
    }

    for (int h=2; h<=max_h; h++) {
        makeLayer(h);
        total_water += getAmount(h);
    }

    printf("%d", total_water);

    return 0;
}