#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M, input[3];
vector<pair<int, int> > city[1001];

struct Vertex {
    int dist;
    int index;
    Vertex(int value, int d):dist(d), index(value) {}
};

struct cmp {
    bool operator() (Vertex v, Vertex u) {
        return v.dist > u.dist;
    }
};

priority_queue<Vertex, vector<Vertex>, cmp> pq;
int dist[1001];

int dijkstra() {
    for (int i=1; i<=N; i++) {
        dist[i] = INT_MAX;
    }
    dist[input[0]] = 0;
    pq.push(Vertex(input[0], 0));

    while (!pq.empty()) {
        Vertex current = pq.top();
        pq.pop();
        if (current.dist > dist[current.index])
            continue;
        
        for (vector<pair<int, int> >::iterator iter = city[current.index].begin(); iter!=city[current.index].end(); iter++) {
            if (dist[iter->first] > dist[current.index] + iter->second) {
                dist[iter->first] = dist[current.index] + iter->second;
                pq.push(Vertex(iter->first, dist[iter->first]));
            }
        }
    }

    return 0;
}

int main(void) {
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &input[0], &input[1], &input[2]);
        city[input[0]].push_back(make_pair(input[1], input[2]));
    }
    scanf("%d %d", &input[0], &input[1]);
    dijkstra();
    printf("%d", dist[input[1]]);
    return 0;
}