#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M, input[2], indegree[32001];
vector<int> v[32001];
priority_queue<int> pq;

int main(void) {
    int front;
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &input[0], &input[1]);
        v[input[0]].push_back(input[1]);
        indegree[input[1]]++;
    }

    for (int i=1; i<=N; i++) {
        if (!indegree[i])
            pq.push(-i);
    }

    while (!pq.empty()) {
        front = pq.top();
        pq.pop();
        printf("%d ", -front);
        for (int child : v[-front]) {
            if(!--indegree[child])
                pq.push(-child);
        }
    }
    return 0;
}