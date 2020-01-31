#include <cstdio>

int main(void) {
    long long N;
    long long sum = 0;
    scanf("%lld", &N);

    int i=0;
    long long digit = 1;
    while (N>0) {
        sum += (N&(long long)1) * digit;
        N = N >> 1;
        i++;
        digit *= 3;
    }
    printf("%lld\n", sum);

    return 0;
}