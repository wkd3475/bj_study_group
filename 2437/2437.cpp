#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> weights;

int main(void) {
    int N, input;
    int sum = 0;
    scanf("%d", &N);

    while (N--) {
        scanf("%d", &input);
        weights.push_back(input);
    }

    sort(weights.begin(), weights.end());

    vector<int>::iterator iter;
    for(iter=weights.begin(); iter!=weights.end(); iter++) {
        if (*iter-sum>1)
            break;
        
        sum += *iter;
    }

    printf("%d\n", sum+1);

    return 0;
}