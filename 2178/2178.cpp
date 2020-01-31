#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int maze[102][102];
int isVisted[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
queue<pair<int, int> > bfs_queue;

void bfs() {
    pair<int, int> front;
    while (!bfs_queue.empty()) {
        front = bfs_queue.front();
        for (int i=0; i<4; i++) {
            if (front.first+dy[i]<0||front.first+dy[i]>=N)
                continue;
            if (front.second+dx[i]<0||front.second+dx[i]>=M)
                continue;
            
            if (maze[front.first+dy[i]][front.second+dx[i]]==1 && !isVisted[front.first+dy[i]][front.second+dx[i]]) {
                if (front.first+dy[i]==N-1&&front.second+dx[i]==M-1) {
                    printf("%d\n", isVisted[front.first][front.second]+1);
                    return;
                }
                bfs_queue.push(make_pair(front.first+dy[i], front.second+dx[i]));
                isVisted[front.first+dy[i]][front.second+dx[i]]=isVisted[front.first][front.second]+1;
            }
        }
        bfs_queue.pop();
    }
}

int main(void) {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs_queue.push(make_pair(0, 0));
    isVisted[0][0] = 1;
    bfs();

    return 0;
}