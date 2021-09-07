#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int num_computer, num_line;
int node[2], weight;
vector<pair<int, int> > lines[1001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int isVisited[1001];

int prim() {
    int result = 0;
    pq.push(make_pair(0, 1));
    
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        if (isVisited[top.second])
            continue;
        isVisited[top.second] = 1;
        result += top.first;

        for (pair<int, int> line : lines[top.second]) {
            if (!isVisited[line.second])
                pq.push(line);
        }
    }
    return result;
}

int main(void) {
    scanf("%d", &num_computer);
    scanf("%d", &num_line);

    for (int i=0; i<num_line; i++) {
        scanf("%d %d %d", &node[0], &node[1], &weight);
        lines[node[0]].push_back(make_pair(weight, node[1]));
        lines[node[1]].push_back(make_pair(weight, node[0]));
    }

    printf("%d", prim());
    
    return 0;
}