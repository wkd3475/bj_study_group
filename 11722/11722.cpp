#include <cstdio>
#include <algorithm>
#include <stdlib.h>

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
    int size;
    int *inputs;
    int *memory;
    scanf("%d", &size);
    inputs = (int*) malloc(sizeof(int)*size);
    memory = (int*) malloc(sizeof(int)*size);

    scanf("%d", &inputs[0]);
    for (int i=0; i<size; i++) {
        memory[i] = 1;
    }

    for (int i=1; i<size; i++) {
        scanf("%d", &inputs[i]);
        for (int j=0; j<i; j++) {
            if (inputs[j] > inputs[i]) {
                memory[i] = std::max(memory[i], memory[j]+1);
            }
        }
    }
    printf("%d\n", getMax(memory, size));
    free(inputs);
    free(memory);

    return 0;
}