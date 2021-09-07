#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int num_house, num_road;
int node[2], weight;
vector<pair<int, int> > roads[1000001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int isVisited[100001];

int prim() {
    int result = 0;
    int max_val = 0;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        if (isVisited[top.second])
            continue;

        isVisited[top.second] = 1;
        result += top.first;

        if (max_val < top.first)
            max_val = top.first;

        for (pair<int, int> road : roads[top.second]) {
            if (!isVisited[road.second])
                pq.push(road);
        }
    }
    return result-max_val;
}
int main(void) {
    scanf("%d %d", &num_house, &num_road);
    for (int i=0; i<num_road; i++) {
        scanf("%d %d %d", &node[0], &node[1], &weight);
        roads[node[0]].push_back(make_pair(weight, node[1]));
        roads[node[1]].push_back(make_pair(weight, node[0]));
    }

    printf("%d", prim());
    return 0;
}
