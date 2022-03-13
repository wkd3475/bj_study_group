#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1234567890

vector<pair<int, int> > edges[1001];
int dp[1001];
int is_visited[1001];

int dfs(int num, int before, int testcase) {
    is_visited[num] = testcase;
    int result = 0, base=MAX;
    for (vector<pair<int, int> >::iterator iter=edges[num].begin(); iter!=edges[num].end(); iter++) {
        if (iter->first == before) {
            base = iter->second;
            continue;
        }

        if (is_visited[iter->first] == testcase) {
            continue;
        }
        
        if (dp[iter->first] == 0)
            result += dfs(iter->first, num, testcase); 
        else
            result += dp[iter->first];
    }

    if (edges[num].size() == 1)
        return dp[num] = base;
    return dp[num] = min(result, base);
}

void init_params() {
    for (int i=0; i<1001; i++) {
        edges[i].clear();
        dp[i] = 0;
        vector<pair<int, int> >().swap(edges[i]);
    }
}

int main(void) {
    int testcase, N, M;
    int input[3];
    int result;

    scanf("%d", &testcase);
    for (int i=1; i<=testcase; i++) {
        result = 0;
        scanf("%d %d", &N, &M);
        for(int i=1; i<=M; i++) {
            scanf("%d %d %d", &input[0], &input[1], &input[2]);
            edges[input[0]].push_back(make_pair(input[1], input[2]));
            edges[input[1]].push_back(make_pair(input[0], input[2]));
        }
        is_visited[1] = testcase;
        for (vector<pair<int, int> >::iterator iter=edges[1].begin(); iter!=edges[1].end(); iter++) {
            result += dfs(iter->first, 1, i);
        }
        printf("%d\n", result);
        init_params();
    }
    return 0;
}

//  start at : 2022-03-13 14:10
// solved at : 2022-03-13 23:13
// 중간에 좀 많이 쉬었음.