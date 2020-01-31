#include <cstdio>

void drawSpace(int n) {
    if (n==0) {
        return;
    }
    printf(" ");
    drawSpace(n-1);
}

void drawStar(int n) {
    if (n==0) {
        printf("\n");
        return;
    }
    printf("*");
    drawStar(n-1);
}

void solve(int n, int max) {
    if (n==0) {
        return;
    }
    drawSpace(max-n);
    drawStar(n);
    solve(n-1, max);
}

int main(void) {
    int N;
    scanf("%d", &N);
    solve(N, N);
    return 0;
}