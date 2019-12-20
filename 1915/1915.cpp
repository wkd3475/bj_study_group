#include <cstdio>
#include <algorithm>
using namespace std;

int memory[1001][1001];

int main() {
    int n, m, input, max=0;
    scanf("%d %d", &n, &m);

    for (int i=0; i<=n; i++) {
        memory[i][0] = 0;
    }

    for (int i=0; i<=m; i++) {
        memory[0][i] = 0;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%1d", &input);

            if (input==1) {
                memory[i][j] = min(min(memory[i-1][j], memory[i][j-1]), memory[i-1][j-1]) + 1;
                if (max < memory[i][j]) {
                    max = memory[i][j];
                }
            } else {
                memory[i][j] = 0;
            }
        }
    }

    printf("%d\n", max*max);

    return 0;
}