#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M, input[2], indegree[32001];
int front;
vector<int> v[32001];
priority_queue<int> pq;

int main(void) {
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &input[0], &input[1]);
        v[input[0]].push_back(input[1]);
        indegree[input[1]]++;
    }

    for (int i=1; i<=N; i++) {
        if (indegree[i]==0)
            pq.push(i);
    }

    while (!pq.empty()) {
        front = pq.top();
        pq.pop();
        printf("%d ", front);
        for (vector<int>::iterator iter=v[front].begin(); iter!=v[front].end(); iter++) {
            indegree[*iter]--;
            if (indegree[*iter]==0)
                pq.push(*iter);
        }
    }

    return 0;
}