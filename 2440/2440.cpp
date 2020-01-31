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
    if (n==0) {
        return;
    }
    draw(n);
    solve(n-1);
}

int main(void) {
    int N;
    scanf("%d", &N);
    solve(N);
    return 0;
}