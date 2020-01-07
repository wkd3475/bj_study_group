#include <cstdio>
#include <climits>

using namespace std;

int main() {
    int N;
    int maxThree;
    int result=INT_MAX;

    scanf("%d", &N);
    maxThree = N/3;

    if (N%5 == 0 && result > N/5)
        result = N/5;
   
    for (int i=1; i<=maxThree; i++) {
        N = N - 3;

        if (N%5 == 0 && result > N/5 + i)
            result = N/5 + i;
    }

    if (result==INT_MAX)
        printf("-1\n");
    else
        printf("%d\n", result);
    return 0;
}