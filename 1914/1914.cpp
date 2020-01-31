#include <cstdio>
#define BigIntMax 10000000000000000

typedef struct bigInt {
    long long high;
    long long low;
} BigInt;

BigInt BigIntDouble(BigInt a) {
    a.high *= 2;
    if (BigIntMax - a.low <= a.low) {
        a.high += 1;
        a.low = (a.low - BigIntMax) + a.low;
    } else {
        a.low += a.low;
    }
    return a;
};

void hanoi(int level, int one, int two, int three) {
    if (level == 1) {
        printf("%d %d\n", one, three);
    } else {
        hanoi(level-1, one, three, two);
        printf("%d %d\n",one, three);
        hanoi(level-1, two, one, three);
    }
}

BigInt pow2(int n) {
    BigInt a;
    a.high = 0;
    a.low = 1;

    if (n == 0) {
        return a;
    }
    a = BigIntDouble(pow2(n-1));
    return a;
}

BigInt BigIntMinus(BigInt a, BigInt b) {
    if (a.low < b.low) {
        a.high -= 1;
        a.low = (BigIntMax - b.low) + a.low;
    } else {
        a.low = a.low - b.low;
    }
    a.high = a.high - b.high;
    return a;
}

int main(void) {
    int N;
    BigInt result;
    BigInt one;
    one.high = 0;
    one.low = 1;
    scanf("%d", &N);
    result = BigIntMinus(pow2(N), one);
    if (result.high>0) {
        printf("%lld%lld\n", result.high, result.low);
    } else {
        printf("%lld\n", result.low);
    }
    
    if (N<=20)
        hanoi(N, 1, 2, 3);
    return 0;
}