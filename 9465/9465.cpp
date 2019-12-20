#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {
    int testcase, num;
    int *stickers[2];
    int *memory[3];
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d", &num);
        for (int i=0; i<3; i++) {
            memory[i] = (int*) malloc(sizeof(int)*num);
        }
        for (int i=0; i<2; i++) {
            stickers[i] = (int*) malloc(sizeof(int)*num);
            for (int j=0; j<num; j++){
                scanf("%d", &stickers[i][j]);
            }
        }

        memory[0][0] = stickers[0][0];
        memory[1][0] = stickers[1][0];
        memory[2][0] = 0;

        for (int i=1; i<num; i++) {
            memory[0][i] = max(memory[1][i-1], memory[2][i-1])+stickers[0][i];
            memory[1][i] = max(memory[0][i-1], memory[2][i-1])+stickers[1][i];
            memory[2][i] = max(memory[0][i-1], memory[1][i-1]);
        }

        printf("%d\n", max(max(memory[0][num-1], memory[1][num-1]), memory[2][num-1]));
        free(stickers[0]);
        free(stickers[1]);
        for (int i=0; i<3; i++) {
            free(memory[i]);
        }
    }
    return 0;
}