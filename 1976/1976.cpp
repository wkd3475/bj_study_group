#include <cstdio>

int parent[201];
int rank[201];

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

    int aRank = rank[aRoot];
    int bRank = rank[bRoot];

    if (aRank < bRank)
        parent[aRoot] = bRoot;
    else if (aRank > bRank)
        parent[bRoot] = aRoot;
    else {
        parent[aRoot] = bRoot;
        rank[bRoot]++;
    }
}

int main(void) {
    int N, M;
    int input;
    int root;
    int check=0;
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i=0; i<N; i++) {
        parent[i] = i;
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &input);
            if (input==1) {
                _union(i, j);
            }
        }
    }

    scanf("%d", &input);
    root = find(input);

    for (int i=1; i<M; i++) {
        scanf("%d", &input);
        if (root != find(input))
            check=1;
    }
    if (check==0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}