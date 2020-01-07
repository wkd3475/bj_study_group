#include <cstdio>
#include <cstring>

using namespace std;

int students[100001];
bool visited[100001];
bool group[100001];
int sum;

void dps(int key);

int main(void) {
    int testcase, n;
    scanf("%d", &testcase);

    while (testcase--){
        memset(visited, false, sizeof(visited));
        memset(group, false, sizeof(group));
        sum = 0;
        scanf("%d", &n);
        for (int i=1; i<=n; i++) {
            scanf("%d", &students[i]);
        }

        for (int i=1; i<=n; i++) {
            if (!visited[i]) {
                dps(i);
            }
        }

        printf("%d\n", n-sum);
    }

    return 0;
}

void dps(int key) {
    visited[key] = true;
    if (visited[students[key]]) {
        if (!group[students[key]]) {
            for (int i=students[key]; i!=key; i=students[i]) {
                sum++;
            }
            sum++;
        }
    } else {
        dps(students[key]);
    }
    group[key] = 1;

    return ;
}