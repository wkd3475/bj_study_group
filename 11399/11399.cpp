#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> times;
    int N, input, sum=0;

    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        scanf("%d", &input);
        times.push_back(input);
    }

    sort(times.begin(), times.end());

    for (vector<int>::iterator iter=times.begin(); iter!=times.end(); iter++) {
        sum += *iter * N--;
    }

    printf("%d\n", sum);
    
    return 0;
}