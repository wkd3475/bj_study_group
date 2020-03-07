#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int testcase, N, M, input[2];
vector<vector<int> > scc;
vector<int> scc_connected[100001];
vector<int> connected[100001];
int dfs_size = 0;
int scc_num = 0;
int block_to_scc[100001];
int min_node[100001];
int finished[100001];
int indegree[100001];
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
        vector<int> temp;
        while (true) {
            int top_element = s.top();
            temp.push_back(top_element);
            block_to_scc[top_element] = scc_num;
            finished[top_element] = 1;
            s.pop();
            if (top_element==now)
                break;
        }
        scc_num++;
        scc.push_back(temp);
    }
    return min_node[now];
}

int main(void) {
    scanf("%d", &testcase);
    while(testcase--) {
        dfs_size = 0;
        scc_num = 0;
        scc.clear();
        for (int i=0; i<100001; i++) {
            scc_connected[i].clear();
            connected[i].clear();
            block_to_scc[i] = 0;
            min_node[i] = 0;
            finished[i] = 0;
            indegree[i] = 0;
        }
        
        int result = 0;
        scanf("%d %d", &N, &M);
        for (int i=0; i<M; i++) {
            scanf("%d %d", &input[0], &input[1]);
            connected[input[0]].push_back(input[1]);
        }

        for (int i=1; i<=N; i++) {
            if (!finished[i])
                tarjan(i);
        }

        int index = 0;
        for (vector<int> scc_node : scc) {
            for (int element : scc_node) {
                for (int conn : connected[element]) {
                    if (block_to_scc[conn]!=index) {
                        scc_connected[index].push_back(block_to_scc[conn]);
                        indegree[block_to_scc[conn]]++;
                    }
                }
            }
            index++;
        }

        for (int i=0; i<index; i++) {
            if (!indegree[i])
                result++;
        }

        printf("%d\n", result);
    }
    
    return 0;
}