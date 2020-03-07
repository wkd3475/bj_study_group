#include <cstdio>

int parent[100001];

int find(int a) {
    if (a==parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void _union(int a, int b) {
    int aRoot = find(a);
    int bRoot = find(b);

    parent[bRoot] = aRoot;
}

int main(void) {
    int G, P;
    int g;
    int result = 0;
    int flag = 0;
    scanf("%d", &G);
    scanf("%d", &P);
    for (int i=0; i<=G; i++) {
        parent[i] = i;
    }

    while (P--) {
        scanf("%d", &g);
        if (find(g)==0) {
            flag = 1;
        }
        else if (flag == 0) {
            _union(find(g)-1, g);
            result++;
        }
    }
    printf("%d\n", result);
    return 0;
}