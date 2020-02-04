#include <cstdio>

void finderY(int n, int x, int y);
void finderX(int n, int x, int y);
void drawer(int n, int x, int y);

int main(void) {
    int N;
    scanf("%d", &N);
    finderY(N, 0, 0);
    return 0;
}

void finderY(int n, int x, int y) {
    if (y==n) {
        return;
    }
    finderX(n, x, y);
    finderY(n, x, y+1);
}

void finderX(int n, int x, int y) {
    if (x==n) {
        printf("\n");
        return;
    }
    drawer(n, x, y);
    finderX(n, x+1, y);
}

void drawer(int n, int x, int y) {
    if (n==1) {
        printf("*");
        return;
    }

    if (x>=n/3 && x<n/3*2 && y>=n/3 && y<n/3*2) {
        printf(" ");
        return;
    }

    drawer(n/3, x%(n/3), y%(n/3));
}