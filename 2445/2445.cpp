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
        return;
    }
    printf("*");
    drawStar(n-1);
}

void solve(int n, int max, int type) {
    if (n==0) {
        return;
    }
    if (type==1) {
        drawStar(n);
        drawSpace(2*(max-n));
        drawStar(n);
        printf("\n");
    }
    solve(n-1, max, type);
    if (type==2) {
        drawStar(n);
        drawSpace(2*(max-n));
        drawStar(n);
        printf("\n");
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    solve(N, N, 2);
    solve(N-1, N, 1);
    return 0;
}