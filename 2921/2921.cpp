#include <cstdio>

int main(void) {
    int N;
    int sum=0;
    scanf("%d", &N);

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=i; j++) {
            sum += i+j;
        }
    }

    printf("%d\n", sum);
    return 0;
}