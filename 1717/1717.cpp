#include <cstdio>

int parent[1000001];
int rank[1000001];

int find(int a) {
    if (a==parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void _union(int a, int b) {
    int aRoot = find(a);
    int bRoot = find(b);

    if (aRoot==bRoot) {
        return;
    }
    
    int aLevel = rank[a];
    int bLevel = rank[b];

    if (aLevel < bLevel)
        parent[aRoot] = bRoot;
    else if (aLevel > bLevel)
        parent[bRoot] = aRoot;
    else {
        parent[aRoot] = bRoot;
        rank[bRoot]++;
    }
}

int main(void) {
    int N, M;
    int a, b, c;
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) {
        parent[i] = i;
    }

    while (M--) {
        scanf("%d %d %d", &a, &b, &c);
        if (a==0) {
            _union(b, c);
        } else {
            if (find(b) == find(c))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}