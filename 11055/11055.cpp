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
    int size;
    int *memory, *input;
    scanf("%d", &size);
    memory = (int*) malloc(sizeof(int)*size);
    input = (int*) malloc(sizeof(int)*size);
    for (int i=0; i<size; i++) {
        scanf("%d", &input[i]);
        memory[i] = input[i];
    }

    for (int i=0; i<size; i++) {
        for (int j=0; j<i; j++) {
            if (input[i]>input[j])
                memory[i]=std::max(memory[i], memory[j]+input[i]);
        }
    }
    printf("%d\n", getMax(memory, size));

    free(memory);
    free(input);

    return 0;
}