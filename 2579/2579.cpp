#include <cstdio>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int num_stairs;
    int input;
    int current[2]={0,0};
    int prev_one_step[2]={0, 0};
    int prev_two_step[2]={0, 0};

    scanf("%d", &num_stairs);

    for (int i=0; i<num_stairs; i++) {
        scanf("%d", &input);
        if (i==0) {
            current[0] = input;
            current[1] = 0;
        } else if (i==1) {
            current[0] = prev_one_step[0] + input;
            current[1] = input;
        } else {
            current[0] = prev_one_step[1] + input;
            current[1] = max(prev_two_step[0], prev_two_step[1]) + input;
        }
        
        prev_two_step[0] = prev_one_step[0];
        prev_two_step[1] = prev_one_step[1];
        prev_one_step[0] = current[0];
        prev_one_step[1] = current[1];
    }

    printf("%d\n", max(current[0], current[1]));
}