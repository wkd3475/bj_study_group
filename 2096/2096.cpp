#include <cstdio>
#include <algorithm>

using namespace std;

int inputs[3];
int minDP[2][3] = {0,};
int maxDP[2][3] = {0,};

int main() {
    int N;
    
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        scanf("%d %d %d", &inputs[0], &inputs[1], &inputs[2]);
        
        minDP[i%2][0] = min(minDP[(i+1)%2][0], minDP[(i+1)%2][1])+inputs[0];
        minDP[i%2][1] = min(minDP[(i+1)%2][0], min(minDP[(i+1)%2][1], minDP[(i+1)%2][2]))+inputs[1];
        minDP[i%2][2] = min(minDP[(i+1)%2][1], minDP[(i+1)%2][2])+inputs[2];
        maxDP[i%2][0] = max(maxDP[(i+1)%2][0], maxDP[(i+1)%2][1])+inputs[0];
        maxDP[i%2][1] = max(maxDP[(i+1)%2][0], max(maxDP[(i+1)%2][1], maxDP[(i+1)%2][2]))+inputs[1];
        maxDP[i%2][2] = max(maxDP[(i+1)%2][1], maxDP[(i+1)%2][2])+inputs[2];
    }

    printf("%d %d\n", max(maxDP[(N-1)%2][0], max(maxDP[(N-1)%2][1], maxDP[(N-1)%2][2])), min(minDP[(N-1)%2][0], min(minDP[(N-1)%2][1], minDP[(N-1)%2][2])));

    return 0;
}