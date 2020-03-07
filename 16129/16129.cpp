#include <cstdio>

int R, C;
char arr[12118][12118];
int total = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ddururu[5] = {'1', '0', '0', '1', '0'};

void dfs(int y, int x, int d, int originY, int originX, int beforeY, int beforeX) {
    if (arr[y][x] != ddururu[d])
        return;
        
    if (d==4) {
        total++;
        return;
    }

    int nextX, nextY;
    for (int i=0; i<4; i++) {
        nextX = x+dx[i];
        nextY = y+dy[i];

        if (nextX<1||nextX>C)
            continue;
        if (nextY<1||nextY>R)
            continue;
        if (nextX==beforeX&&nextY==beforeY)
            continue;
        if (nextX==originX&&nextY==originY)
            continue;

        if (arr[nextY][nextX] == ddururu[d+1])
            dfs(y+dy[i], x+dx[i], d+1, originY, originX, y, x);
    }
}

int main(void) {
    scanf("%d %d", &R, &C);

    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            if (((i-1)*C+j-1)%5==0 || ((i-1)*C+j-1)%5==3)
                arr[i][j] = '1';
            else 
                arr[i][j] = '0';
        }
    }

    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            dfs(i, j, 0, i, j, i, j);
        }
    }
    printf("%d", total);

    return 0;
}