#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
#define MAX_N 20003

vector<vector<int> > scc_group;
vector<int> connected[MAX_N];
int dfs_size = 0;
int min_node[MAX_N];
int finished[MAX_N];
int idToSccNum[MAX_N];
int scc_num = 1;
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
            finished[top_element] = 1;
            idToSccNum[top_element] = scc_num;
            s.pop();
            if (top_element==now)
                break;
        }
        scc_num++;
        scc_group.push_back(temp);
    }
    return min_node[now];
}

int inputParamToId(int num) {
    if (num > 0)
        return 2*num;
    return 2*(-num)+1;
}

int main(void) {
    int N, M;
    int input_param[2];
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++) {
        scanf("%d %d", &input_param[0], &input_param[1]);
        connected[inputParamToId(-input_param[0])].push_back(inputParamToId(input_param[1]));
        connected[inputParamToId(-input_param[1])].push_back(inputParamToId(input_param[0]));
    }

    for (int i=2; i<=2*M+1; i++) {
        if (!finished[i])
            tarjan(i);
    }

    for (int i=1; i<=M; i++) {
        if (idToSccNum[2*i] == idToSccNum[2*i+1]) {
            printf("OTL");
            return 0;
        }
    }

    printf("^_^");
    return 0;
}