#include <cstdio>

int main() {
    int T, H, W, N;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d", &H, &W, &N);

        printf("%d\n", (N % H != 0 ? N % H : H)*100 + (N % H != 0 ? N/H + 1 : N/H));
    }

    return 0;
}