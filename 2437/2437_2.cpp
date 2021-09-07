#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> weights;

int main(void) {
    int N, w;
    int sum = 0;

    scanf("%d", &N);

    while (N--) {
        scanf("%d", &w);
        weights.push_back(w);
    }

    sort(weights.begin(), weights.end());

    vector<int>::iterator iter;
    for (iter=weights.begin(); iter!=weights.end(); iter++) {
        if (*iter > sum+1)
            break;
        sum += *iter;
    }

    printf("%d", sum+1);

    return 0;
}