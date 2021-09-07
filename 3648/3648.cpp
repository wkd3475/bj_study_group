#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX_M 2003

vector<vector<int> > scc_group;
vector<int> connected[MAX_M];
int dfs_size = 0;
int min_node[MAX_M];
int finished[MAX_M];
int idToSccNum[MAX_M];
int scc_num = 1;
int result_value[MAX_M];
vector<pair<int, int> >sccNumWithNum;
stack<int> s;

void initValue() {
    scc_group.clear();
    sccNumWithNum.clear();
    for (int i=0; i<MAX_M; i++) {
        connected[i].clear();
        min_node[i] = 0;
        finished[i] = 0;
        idToSccNum[i] = 0;
        result_value[i] = 0;
    }
    dfs_size = 0;
    scc_num = 1;
    while (!s.empty()) {
        s.pop();
    }
}

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

int desc(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}


int main(void) {
    int N, M;
    int input_param[2];
    while (true) {
        int flag = 0;
        initValue();
        if (scanf("%d %d", &N, &M) != 2)
            break;

        for (int i=0; i<M; i++) {
            scanf("%d %d", &input_param[0], &input_param[1]);
            connected[inputParamToId(-input_param[0])].push_back(inputParamToId(input_param[1]));
            connected[inputParamToId(-input_param[1])].push_back(inputParamToId(input_param[0]));
        }

        for (int i=2; i<=2*N+1; i++) {
            if (!finished[i])
                tarjan(i);
        }

        for (int i=1; i<=N; i++) {
            if (idToSccNum[2*i] == idToSccNum[2*i+1]) {
                printf("no\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            for (int i=2; i<= 2*N+1; i++) {
                sccNumWithNum.push_back(make_pair(idToSccNum[i], i));
            }
            sort(sccNumWithNum.begin(), sccNumWithNum.end(), desc);

            for (int i=0; i<2*N; i++) {
                int now = sccNumWithNum[i].second;
                if (result_value[now/2] == 0) {
                    if (now%2==0)
                        result_value[now/2] = -1;
                    else
                        result_value[now/2] = 1;            
                }
            }

            if (result_value[1] == 1)
                printf("yes\n");
            else if (result_value[1] == -1)
                printf("no\n");
        }
    }
    return 0;
}