#include <cstdio>
#include <stdlib.h>

int main() {
    int test_case;
    int left, right;
    int **memory;
    scanf("%d", &test_case);

    memory = (int**) malloc(sizeof(int*)*30);

    for (int i=0; i<30; i++) {
        memory[i] = (int*) malloc(sizeof(int)*(i+1));
        memory[i][i] = 1;
        memory[i][0] = 1;
    }

    for (int i=1; i<30; i++) {
        for (int j=1; j<i; j++) {
            memory[i][j] = memory[i-1][j] + memory[i-1][j-1];
        }
    }

    while (test_case--) {
        scanf("%d %d", &left, &right);
        printf("%d\n", memory[right][left]);
    }

    for (int i=0; i<30; i++) {
        free(memory[i]);
    }
    free(memory);

    return 0;
}