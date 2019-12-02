#include <cstdio>
int memory[100000];

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        memory[i] = i+1;
    }

    for (int i=0; i<N; i++) {
        for (int j=1; j*j<=i+1; j++) {
            if (memory[i] > memory[i-j*j]+1)
                memory[i] = memory[i-j*j]+1;
        }
    }
    printf("%d\n", memory[N-1]);
    return 0;
}