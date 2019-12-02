#include <cstdio>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int num_glass;
    int input;
    int memory[2][3];
    scanf("%d", &num_glass);

    for (int i=0; i<num_glass; i++) {
        scanf("%d", &input);
        if (i==0) {
            memory[0][0] = 0;
            memory[0][1] = input;
            memory[0][2] = 0;
        } else if (i==1) {
            memory[0][0] = memory[1][1];
            memory[0][1] = input;
            memory[0][2] = memory[1][1] + input;
        } else {
            memory[0][0] = max(max(memory[1][0], memory[1][1]), memory[1][2]);
            memory[0][1] = memory[1][0] + input;
            memory[0][2] = memory[1][1] + input;
        }
        memory[1][0] = memory[0][0];
        memory[1][1] = memory[0][1];
        memory[1][2] = memory[0][2];
    }
    printf("%d\n", max(max(memory[0][0], memory[0][1]), memory[0][2]));
    return 0;
}