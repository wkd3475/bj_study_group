#include <cstdio>
#include <stdlib.h>
#include <algorithm>

int getMax(int* array, int size) {
    int max=0;
    for (int i=0; i<size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int main() {
    int size, input;
    int **memory = (int**) malloc(sizeof(int*)*2);
    scanf("%d", &size);
    for (int i=0; i<2; i++) {
        memory[i] = (int*) malloc(sizeof(int)*size);
    }

    for (int i=0; i<size; i++) {
        memory[0][i] = 0;
        memory[1][i] = 0;
    }

    for (int i=0; i<size; i++) {
        scanf("%d", &input);
        memory[i%2][0] = memory[(i+1)%2][0]+input;
        for (int j=1; j<=i; j++) {
            scanf("%d", &input);
            memory[i%2][j] = std::max(memory[(i+1)%2][j-1], memory[(i+1)%2][j])+input;
        }
    }

    printf("%d\n", getMax(memory[(size-1)%2], size));
    return 0;
}