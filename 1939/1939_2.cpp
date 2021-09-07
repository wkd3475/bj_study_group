#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge {
    int to;
    int weight;
    edge(int to, int weight) :to(to), weight(weight) {};
} Edge;

int isVisited[100001];
vector<Edge> nodes[100001];
queue<int> q;

void clean_queue() {
    while (!q.empty())
        q.pop();
}

int bfs(int from, int to, int max_weight, int flag) {
    int now;
    clean_queue();
    
    q.push(from);
    isVisited[from] = flag;

    while (!q.empty()) {
        now = q.front();
        for (vector<Edge>::iterator iter=nodes[now].begin(); iter!=nodes[now].end(); iter++) {
            if (iter->to == to && iter->weight >= max_weight)
                return 1;
            if (iter->weight >= max_weight && isVisited[iter->to]!=flag) {
                q.push(iter->to);
                isVisited[iter->to]=flag;
            }
        }
        q.pop();
    }
    return 0;
}

int main(void) {
    int N, M;
    int A, B, C;
    int from, to;
    int max_value;
    scanf("%d %d", &N, &M);

    while (M--) {
        scanf("%d %d %d", &A, &B, &C);
        nodes[A].push_back(Edge(B, C));
        nodes[B].push_back(Edge(A, C));
        if (max_value < C)
            max_value = C;
    }

    scanf("%d %d", &from, &to);

    int front=1, end=max_value, mid;
    int counter = 1;
    while (front <= end) {
        mid = (front+end)/2;
        if (bfs(from, to, mid, counter)) {
            front = mid+1;
        } else {
            end = mid-1;
        }
        counter++;
    }
    printf("%d", front-1);

    return 0;
}