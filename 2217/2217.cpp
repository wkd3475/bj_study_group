#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ropes;
vector<int> result;

int main(void) {
    int N, input;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &input);
        ropes.push_back(input);
    }

    sort(ropes.begin(), ropes.end());

    vector<int>::iterator iter;
    for (iter=ropes.begin(); iter!=ropes.end(); iter++) {
        result.push_back(*iter * (N--));
    }

    sort(result.begin(), result.end());
    printf("%d\n", result.back());
    return 0;
}