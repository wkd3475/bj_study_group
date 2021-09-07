#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Line {
    int from;
    int to;
    int val;
    Line(int from, int to, int val) : from(from), to(to), val(val) {}
};

struct cmp {
    int operator()(Line t, Line u) {
        return t.val > u.val;
    }
};

int num_computer, num_line;
int node[2], weight;
vector<Line> lines[1001];
priority_queue<Line, vector<Line>, cmp> pq;
int isVisited[1001];
vector<Line> mem;

void prim() {
    pq.push(Line(1, 1, 0));
    while (!pq.empty()) {
        Line top = pq.top();
        pq.pop();

        if (isVisited[top.to])
            continue;

        isVisited[top.to] = 1;
        if (top.val != 0)
            mem.push_back(top);

        for (Line line : lines[top.to]) {
            if (!isVisited[line.to]) {
                line.val += top.val;
                pq.push(line);
            }
        }   
    }
    return;
}
int main(void) {
    scanf("%d %d", &num_computer, &num_line);
    for (int i=0; i<num_line; i++) {
        scanf("%d %d %d", &node[0], &node[1], &weight);
        lines[node[0]].push_back(Line(node[0], node[1], weight));
        lines[node[1]].push_back(Line(node[1], node[0], weight));
    }

    prim();

    printf("%d\n", (int)mem.size());
    for (Line m : mem) {
        printf("%d %d\n", m.from, m.to);
    }
    return 0;
}
