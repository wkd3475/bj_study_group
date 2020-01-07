#include <cstdio>
int arr[25][25];
int count[25*25+1];
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dps(int row, int col);

int main(void) {
    int num = 0;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (arr[i][j]==1) {
                count[dps(i, j)]++;
                num++;
            }
        }
    }

    printf("%d\n", num);
    for (int i=0; i<25*25+1; i++) {
        while (count[i]>0) {
            printf("%d\n", i);
            count[i]--;
        }
    }

    return 0;
}

int dps(int row, int col) {
    int sum = 1;
    arr[row][col] = 0;
    for (int i=0; i<4; i++) {
        if (row+dy[i]<0||row+dy[i]>=N)
            continue;
        if (col+dx[i]<0||col+dx[i]>=N)
            continue;
        if (arr[row+dy[i]][col+dx[i]]==1)
            sum += dps(row+dy[i], col+dx[i]);
    }

    return sum;
}