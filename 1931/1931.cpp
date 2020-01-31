#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        if (a.first < b.first) {
            return 1;
        }
    }
    else if (a.second < b.second) {
        return 1;
    }
    return 0;
}

int main(void) {
    int N, input[2], max=0, count=0;
    scanf("%d", &N);
    vector<pair<int, int> > time_pair;
    while (N--) {
        scanf("%d %d", &input[0], &input[1]);
        time_pair.push_back(make_pair(input[0], input[1]));
    }

    sort(time_pair.begin(), time_pair.end(), compare);

    vector<pair<int, int> >::iterator iter;
    for (iter=time_pair.begin(); iter!=time_pair.end(); iter++) {
        if (max <= iter->first) {
            max = iter->second;
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}