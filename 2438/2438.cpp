#include <cstdio>

void draw(int n) {
    if (n==0) {
        printf("\n");
        return;
    }
    printf("*");
    draw(n-1);
}

void solve(int n) {
    if (n==1) {
        draw(n);
        return;
    }
    solve(n-1);
    draw(n);
}

int main(void) {
    int N;
    scanf("%d", &N);
    solve(N);
    return 0;
}