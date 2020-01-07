#include <cstdio>
int max_x, max_y;
int arr[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void dps(int x, int y) {
    arr[y][x] = 0;
    for (int i=0; i<4; i++) {
        if (x+dx[i]<0||x+dx[i]>=max_x)
            continue;
        if (y+dy[i]<0||y+dy[i]>=max_y)
            continue;
        if (arr[y+dy[i]][x+dx[i]]==1)
            dps(x+dx[i], y+dy[i]);
    }

    return;
}

int main(void) {
    int num_testcase;
    int K;
    int total;
    scanf("%d", &num_testcase);

    while(num_testcase--) {
        total = 0;
        scanf("%d %d %d", &max_x, &max_y, &K);
        while (K--) {
            int x, y;
            scanf("%d %d", &x, &y);
            arr[y][x] = 1;
        }

        for (int i=0; i<max_y; i++) {
            for (int j=0; j<max_x; j++) {
                if (arr[i][j] == 1) {
                    dps(j, i);
                    total++;
                }
            }
        }
        printf("%d\n", total);
    }

    return 0;
}