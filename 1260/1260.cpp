#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edges[10001];
int isVisted[1001];

queue<int> bfs_queue;

void dfs(int vertex) {
    isVisted[vertex] = 1;
    printf("%d ", vertex);
    vector<int>::iterator iter;
    for (iter=edges[vertex].begin(); iter!=edges[vertex].end(); iter++) {
        if (isVisted[*iter]!=1)
            dfs(*iter);
    }
}

void bfs() {
    int front;
    while (bfs_queue.size()) {
        front = bfs_queue.front();
        if (isVisted[front]!=2)
            printf("%d ", front);

        isVisted[front] = 2;
        bfs_queue.pop();
        vector<int>::iterator iter;
        for (iter=edges[front].begin(); iter!=edges[front].end(); iter++) {
            if (isVisted[*iter]!=2) {
                bfs_queue.push(*iter);
            }
        }
    }
}

int main(void) {
    int N, M, V;
    int input[2];
    scanf("%d %d %d", &N, &M, &V);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &input[0], &input[1]);
        edges[input[0]].push_back(input[1]);
        edges[input[1]].push_back(input[0]);
    }

    for (int i=1; i<=M; i++) {
        sort(edges[i].begin(), edges[i].end());
    }
    dfs(V);
    printf("\n");

    bfs_queue.push(V);
    bfs();
    printf("\n");

    return 0;
}