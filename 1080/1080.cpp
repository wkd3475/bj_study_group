#include <cstdio>
using namespace std;

int N, M;
int min_value=0;
int arrayA[51][51];
int arrayB[51][51];

int swapMap(int x, int y) {
    for (int i=y; i<y+3; i++) {
        for (int j=x; j<x+3; j++) {
            arrayA[i][j] ^= 1;
        }
    }
    return 0;
}

int main(void) {
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%1d", &arrayA[i][j]);
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%1d", &arrayB[i][j]);
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (arrayA[i][j]!=arrayB[i][j] && i+2<N && j+2<M) {
                swapMap(j, i);
                min_value++;
            } else if (arrayA[i][j]!=arrayB[i][j] && (i+2>=N||j+2>=M)) {
                printf("-1\n");
                return 0;
            }
        }
    }

    printf("%d\n", min_value);

    return 0;
}