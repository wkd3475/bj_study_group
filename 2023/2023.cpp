#include <cstdio>

int first[4] = {2,3,5,7};
int second[5] = {1,3,5,7,9};

int is_prime(int val) {
    if (val == 1 || val == 0)
        return 0;

    for (int i=2; i*i<=val; i++) {
        if (val % i == 0)
            return 0;
    }
    return 1;
}

void dfs(int val, int level) {
    for (int i=0; i<5; i++) {
        int result = val*10 + second[i];
        if (is_prime(result)) {
            if (level == 1)
                printf("%d\n", result);
            else
                dfs(result, level-1);
        }
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    if (N==1) {
        for (int i=0; i<4; i++)
            printf("%d\n", first[i]);
    }

    for (int i=0; i<4; i++) {
        dfs(first[i], N-1);
    }
    return 0;
}