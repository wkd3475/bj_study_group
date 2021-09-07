#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int is_visited[20001];
vector<int> vertex[20001];
queue<int> q;

void clean_queue() {
    while (!q.empty())
        q.pop();
}

int bfs(int from, int flag) {
    int color[2] = {flag-1, flag};
    clean_queue();
    
    q.push(from);
    is_visited[from] = color[0];

    int now;
    int now_color;
    while (!q.empty()) {
        now = q.front();
        now_color = is_visited[now];
        for (vector<int>::iterator iter=vertex[now].begin(); iter!=vertex[now].end(); iter++) {
            if (is_visited[*iter] == now_color) {
                return 0;
            }

            if (is_visited[*iter] != color[0] && is_visited[*iter] != color[1]) {
                q.push(*iter);
                if (now_color == color[0]) 
                    is_visited[*iter] = color[1];
                else
                    is_visited[*iter] = color[0];
            }
        }
        q.pop();
    }
    return 1;
}

int main(void) {
    int testcase, num_vertex, num_edge;
    int from, to;

    scanf("%d", &testcase);

    while (testcase--) {
        int result;
        scanf("%d %d", &num_vertex, &num_edge);
        while (num_edge--) {
            scanf("%d %d", &from, &to);
            vertex[from].push_back(to);
            vertex[to].push_back(from);
        }
        for (int i=1; i<=num_vertex; i++) {
            if (is_visited[i] == 2*(testcase+1) || is_visited[i] == 2*(testcase+1)-1)
                continue;

            if (bfs(i, 2*(testcase+1)))
                result = true;
            else {
                result = false;
                break;
            }
        }

        if (result)
            printf("YES\n");
        else
            printf("NO\n");
        
        for (int i=1; i<=num_vertex; i++)
            vertex[i].clear();
    }

    return 0;
}