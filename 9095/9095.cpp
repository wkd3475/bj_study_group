#include <cstdio>
using namespace std;

int main() {
    int num_testcase, input;
    scanf("%d", &num_testcase);
    while (num_testcase--) {
        int a[3] = {1, 2, 4};
        scanf("%d", &input);
        if (input <= 3) {
            printf("%d\n", a[input-1]);
        } else {
            for (int i=3; i<input; i++) {
                a[i%3] = a[0]+a[1]+a[2];
            }
            printf("%d\n", a[(input-1)%3]);
        }
    }
    return 0;
}