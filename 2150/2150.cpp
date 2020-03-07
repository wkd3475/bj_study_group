#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int V, E, input[2];
vector<pair<int, vector<int> > > scc;
vector<vector<int> > connected;
int dfs_size = 0;
int min_node[10001];
int finished[10001];
stack<int> s;

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
        int min_element = 987654321;
        vector<int> temp;
        while (true) {
            int top_element = s.top();
            temp.push_back(top_element);
            min_element = min(min_element, top_element);
            finished[top_element] = 1;
            s.pop();
            if (top_element==now)
                break;
        }
        scc.push_back(make_pair(min_element, temp));
    }
    return min_node[now];
}

int cmp(pair<int, vector<int> > a, pair<int, vector<int> > b) {
    if (a.first < b.first)
        return 1;
    return 0;
}

int main(void) {
    scanf("%d %d", &V, &E);
    connected.resize(E+1);
    for (int i=0; i<E; i++) {
        scanf("%d %d", &input[0], &input[1]);
        connected[input[0]].push_back(input[1]);
    }

    for (int i=1; i<=V; i++) {
        if (!finished[i])
            tarjan(i);
    }

    sort(scc.begin(), scc.end(), cmp);
    printf("%lu\n", scc.size());

    for (pair<int, vector<int> > scc_node : scc) {
        sort(scc_node.second.begin(), scc_node.second.end());
        for (int el : scc_node.second) {
            printf("%d ", el);
        }
        printf("-1\n");
    }

    return 0;
}