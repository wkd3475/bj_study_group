#include <cstdio>
using namespace std;

int main() {
    int input;
    int a[2]={1, 2};

    scanf("%d", &input);
    if (input > 2) {
        for (int i=2; i<input; i++) {
            a[i%2] = (a[0]+a[1])%10007;
        }
    }
    printf("%d\n", a[(input-1)%2]);
    
    return 0;
}