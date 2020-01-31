#include <cstdio>

int getValue(int n, int digit) {
    if (n/digit == 0) {
        return n;
    }
    int result = n%digit + getValue(n/digit, digit);
    return result;
}

void iterator(int n) {
    if (n>=1000&&n<=9999) {
        int num = getValue(n, 10);
        if (num==getValue(n, 12) && num==getValue(n, 16)) {
            printf("%d\n", n);
        }
        iterator(n+1);
    }
}

int main(void) {
    iterator(1000);
    return 0;
}