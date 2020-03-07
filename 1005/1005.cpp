#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int testcase, N, K, W, input[2], indegree[1001];
int result[1001];
int build_time[1001];
vector<int> v[1001];

struct cmp {
    int operator() (int a, int b) {
        return build_time[a] > build_time[b];
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main(void) {
    int front;
    scanf("%d", &testcase);

    while (!pq.empty()) {
        printf("%d\n", pq.top());
        pq.pop();
    }

    while (testcase--) {
        for (int i=0; i<1001; i++) {
            v[i].clear();
        }

        scanf("%d %d", &N, &K);
        for (int i=1; i<=N; i++) {
            scanf("%d", &build_time[i]);
            result[i] = build_time[i];
        }
        for (int i=1; i<=K; i++) {
            scanf("%d %d", &input[0], &input[1]);
            v[input[0]].push_back(input[1]);
            indegree[input[1]]++;
        }
        scanf("%d", &W);

        for (int i=1; i<=N; i++) {
            if (!indegree[i])
                pq.push(i);
        }

        while (!pq.empty()) {
            front = pq.top();
            pq.pop();
            for (int child : v[front]) {
                result[child] = max(result[child], result[front]+build_time[child]);
                if(!--indegree[child])
                    pq.push(child);
            }
        }

        printf("%d\n", result[W]);
    }
    return 0;
}