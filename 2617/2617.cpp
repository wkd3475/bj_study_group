#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> heavier[100], lighter[100];
bool result[100];
bool visited[100];

int dpsHeavier(int marble) {
    int depth = 0;
    visited[marble] = true;
    for (int i=0; i<heavier[marble].size(); i++) {
        if (!visited[heavier[marble][i]]) {
            depth += dpsHeavier(heavier[marble][i])+1;
        }
    }
    return depth;
}

int dpsLighter(int marble) {
    int depth = 0;
    visited[marble] = true;
    for (int i=0; i<lighter[marble].size(); i++) {
        if (!visited[lighter[marble][i]]) {
            depth += dpsLighter(lighter[marble][i])+1;
        }
    }
    return depth;
}

int main(void) {
    int marble_num, set_num;
    int heavy, light;
    int sum = 0;

    scanf("%d %d", &marble_num, &set_num);

    for (int i=0; i<set_num; i++) {
        scanf("%d %d", &heavy, &light);
        heavier[light].push_back(heavy);
        lighter[heavy].push_back(light);
    }

    for (int i=1; i<=marble_num; i++) {
        memset(visited, false, sizeof(visited));
        if (dpsHeavier(i)>=(marble_num+1)/2) {
            result[i] = true;
        }
            
        memset(visited, false, sizeof(visited));
        if (dpsLighter(i)>=(marble_num+1)/2) {
            result[i] = true;
        }
    }

    for (int i=1; i<=marble_num; i++) {
        if (result[i])
            sum++;
    }

    printf("%d\n", sum);

    return 0;
}