#include <cstdio>

int main() {
    long long a[3];
    int n;

    scanf("%d", &n);

    a[0] = 0;
    a[1] = 1;

    for (int i=2; i<=n; i++) {
        a[i%3] = a[(i+1)%3] + a[(i+2)%3];
    }

    printf("%lld\n", a[n%3]);
    return 0;
}