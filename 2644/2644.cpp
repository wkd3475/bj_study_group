#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, input[2];
int person[2];
int isVisited[102];
vector<int> edges[102];
queue<int> bfs_queue;

int bfs() {
    int front;
    while (!bfs_queue.empty()) {
        front = bfs_queue.front();
        vector<int>::iterator iter;
        for (iter=edges[front].begin(); iter!=edges[front].end(); iter++) {
            if (!isVisited[*iter]) {
                if (*iter==person[1]) {
                    return isVisited[front];
                }
                bfs_queue.push(*iter);
                isVisited[*iter] = isVisited[front]+1;
            }
        }
        bfs_queue.pop();
    }
    return -1;
}

int main(void) {
    scanf("%d", &n);
    scanf("%d %d", &person[0], &person[1]);
    scanf("%d", &m);

    for (int i=1; i<=m; i++) {
        scanf("%d %d", &input[0], &input[1]);
        edges[input[0]].push_back(input[1]);
        edges[input[1]].push_back(input[0]);
    }

    bfs_queue.push(person[0]);
    isVisited[person[0]] = 1;
    printf("%d\n", bfs());
    return 0;
}