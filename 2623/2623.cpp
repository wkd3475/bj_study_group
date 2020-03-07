#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M, input[2], indegree[1001];
vector<int> v[1001];
vector<int> result;
priority_queue<int> pq;

int main(void) {
    int before, front;
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        scanf("%d", &input[0]);
        input[0]--;
        scanf("%d", &input[1]);
        while (input[0]--) {
            before = input[1];
            scanf("%d", &input[1]);
            v[before].push_back(input[1]);
            indegree[input[1]]++;
        }
    }

    for (int i=1; i<=N; i++) {
        if (!indegree[i])
            pq.push(i);
    }

    while (!pq.empty()) {
        front = pq.top();
        pq.pop();
        result.push_back(front);
        for (int child : v[front]) {
            if(!--indegree[child])
                pq.push(child);
        }
    }

    if (result.size()==N) {
        for (int val : result) {
            printf("%d\n", val);
        }
    } else {
        printf("0");
    }
    return 0;
}