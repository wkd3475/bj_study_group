#include <cstdio>
int memory[101][100][2];

int main() {
    int num_testcase, N, K;
    scanf("%d", &num_testcase);

    memory[1][0][0] = 1;
    memory[1][0][1] = 1;

    for (int n=2; n<=100; n++) {
        for (int k=0; k<n; k++) {
            memory[n][k][0] = memory[n-1][k][0] + memory[n-1][k][1];
            memory[n][k][1] = memory[n-1][k-1][1] + memory[n-1][k][0];
        }
    }

    while (num_testcase--) {
        scanf("%d %d", &N, &K);
        printf("%d\n", memory[N][K][0]+memory[N][K][1]);
    }

    return 0;
}