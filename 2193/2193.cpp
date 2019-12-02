#include <iostream>
using namespace std;

int main() {
    long memory[2]={1, 1};
    int input;
    scanf("%d", &input);

    if (input<3) {
        printf("%ld\n", memory[input-1]);
    } else {
        for (int i=2; i<input; i++) {
            memory[i%2] = memory[0] + memory[1];
        }
        printf("%ld\n", memory[(input-1)%2]);
    }

    return 0;
}