#include <cstdio>
#define MAX 6

int arr[12];
int stack[12];
int input;
void dps(int depth, int num);

int main(void) {
    while (true) {
        scanf("%d", &input);
        
        if (input == 0)
            break;

        for (int i=0; i<input; i++)
            scanf("%d", &arr[i]);

        for (int i=0; i+MAX<=input; i++) {
            dps(1, i);
        }
        
        printf("\n");
    }
    return 0;
}

void dps(int depth, int num) {
    stack[num] = 1;
    
    if (depth==MAX) {
        for (int i=0; i<input; i++) {
            if (stack[i]==1) {
                printf("%d ", arr[i]);
            }
        }
        printf("\n");
        stack[num]--;
        return;
    }

    for (int i=num+1; i<input; i++) {
        if (stack[i]==0) {
            dps(depth+1, i);
        }
    }
    stack[num]--;
    return;
}