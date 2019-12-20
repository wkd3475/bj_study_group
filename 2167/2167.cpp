#include <cstdio>

int array[301][301];

int main() {
    int N, M, K, input;
    int i, j, x, y;
    scanf("%d %d", &N, &M);

    for (int n=0; n<=N; n++) {
        array[n][0] = 0;
    }

    for (int m=1; m<=M; m++) {
        array[0][m] = 0;
    }

    for (int n=1; n<=N; n++) {
        for (int m=1; m<=M; m++) {
            scanf("%d", &array[n][m]);
            array[n][m] = array[n-1][m] + array[n][m-1] - array[n-1][m-1] + array[n][m];
        }
    }

    scanf("%d", &K);

    while (K--) {
        scanf("%d %d %d %d", &i, &j, &x, &y);
        printf("%d\n", array[x][y] - array[i-1][y] - array[x][j-1] + array[i-1][j-1]);
    }

    return 0;
}