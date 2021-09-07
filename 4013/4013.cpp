#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
#define MAX_VAL 500001
using namespace std;

struct Group {
    int index;
    int money;
    int isRest;
    set<int> to;
};

int N, M, S, P, input[2];
int indegree[MAX_VAL];
vector<vector<int> >scc;
vector<int> connected[MAX_VAL];
vector<Group> groups;
int money[MAX_VAL];
int nodeToIndex[MAX_VAL];
int dfs_size = 0;
int min_node[MAX_VAL];
int finished[MAX_VAL];
int rest[MAX_VAL];
int max_money[MAX_VAL];
stack<int> s;
queue<int> q;

int group_num = 0;

int tarjan(int now) {
    int dfs_num = ++dfs_size;
    min_node[now] = dfs_num;
    s.push(now);
    for (int next : connected[now]) {
        if (min_node[next]==0) {
            min_node[now] = min(min_node[now], tarjan(next));
        } else if (!finished[next]) {
            min_node[now] = min(min_node[now], min_node[next]);
        }
    }
    if (dfs_num==min_node[now]) {
        vector<int> temp;
        while (true) {
            int top_element = s.top();
            temp.push_back(top_element);
            nodeToIndex[top_element] = group_num;
            finished[top_element] = 1;
            s.pop();
            if (top_element==now)
                break;
        }
        scc.push_back(temp);
        group_num++;
    }
    return min_node[now];
}

int main(void) {
    scanf("%d %d", &N, &M);

    for (int i=0; i<M; i++) {
        scanf("%d %d", &input[0], &input[1]);
        connected[input[0]].push_back(input[1]);
    }

    for (int i=1; i<=N; i++) {
        scanf("%d", &money[i]);
    }

    scanf("%d %d", &S, &P);

    for (int i=0; i<P; i++) {
        scanf("%d", &input[0]);
        rest[input[0]] = 1;
    }

    for (int i=1; i<=N; i++) {
        if (!finished[i])
            tarjan(i);
    }

    int index = 0;
    for (vector<int> v : scc) {
        Group g;
        g.isRest = 0;
        int sum = 0;
        for (int element : v) {
            sum += money[element];
            if (rest[element]==1)
                g.isRest = 1;
        }
        g.index = index;
        g.money = sum;
        groups.push_back(g);
        index++;
    }
    
    for (int i=1; i<=N; i++) {
        for (int c : connected[i]) {
            if (nodeToIndex[c] != nodeToIndex[i]) {
                if (groups[nodeToIndex[c]].to.count(nodeToIndex[i])==0) {
                    groups[nodeToIndex[c]].to.insert(nodeToIndex[i]);
                    indegree[nodeToIndex[i]]++;
                }
            }
        }
    }

    for (Group g : groups) {
        if (indegree[g.index]==0) {
            q.push(g.index);
        }
    }

    for (int i=0; i<index; i++) {
        max_money[i] = groups[i].money;
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : groups[now].to) {
            if (groups[now].isRest) {
                max_money[next] = max(max_money[next], max_money[now]+groups[next].money);
                groups[next].isRest = 1;
            }
            if (--indegree[groups[next].index]==0) {
                q.push(next);
            }
        }
    }

    printf("%d", max_money[nodeToIndex[S]]);

    return 0;
}