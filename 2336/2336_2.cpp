#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node {
    int val[2];
} Node;

typedef struct treeNode {
    int val;
    int rightCover;
    int leftCover;
} TreeNode;

Node nodes[500001];

int checker[500001];

TreeNode tree[2<<20];

int logN(int n) {
    int result=0;
    while (n>0) {
        n /= 2;
        result++;
    }
    return result;
}

int powTwo(int n) {
    int result=1;
    while (n>0) {
        result *= 2;
        n--;
    }
    return result;
}

void makeTree(int n) {
    for (int i=0; i<powTwo(logN(n)); i++) {
        tree[powTwo(logN(n))+i].rightCover = powTwo(logN(n))+i;
        tree[powTwo(logN(n))+i].leftCover = powTwo(logN(n))+i;
    }

    for (int i=logN(n)-1; i>=0; i--) {
        for (int j=0; j<powTwo(i); j++) {
            tree[powTwo(i)+j].val=0;
            tree[powTwo(i)+j].leftCover = tree[(powTwo(i)+j)*2].leftCover;
            tree[powTwo(i)+j].rightCover = tree[(powTwo(i)+j)*2+1].rightCover;
        }
    }
}

void update(int n, int val) {
    tree[n].val = val;

    while (n>1) {
        if (tree[(n/2)*2].val==0&&tree[(n/2)*2+1].val!=0) {
            tree[n/2].val = tree[(n/2)*2+1].val;
        } else if (tree[(n/2)*2].val!=0&&tree[(n/2)*2+1].val==0) {
            tree[n/2].val = tree[(n/2)*2].val;
        } else if (tree[(n/2)*2].val!=0&&tree[(n/2)*2+1].val!=0) {
            tree[n/2].val = min(tree[(n/2)*2].val, tree[(n/2)*2+1].val);
        }
        
        n /= 2;
    }
}

int getValue(int from, int to, int nodeNum) {
    if (tree[nodeNum].leftCover==from && tree[nodeNum].rightCover==to) {
        return tree[nodeNum].val;
    }

    int mid = (tree[nodeNum].rightCover + tree[nodeNum].leftCover)/2;

    if (from<=mid && to>mid) {
        int a = getValue(from, mid, nodeNum*2);
        int b = getValue(mid+1, to, nodeNum*2+1);
        if (a==0 && b==0) {
            return 0;
        } else if (a!=0 && b==0) {
            return a;
        } else if (a==0 && b!=0) {
            return b;
        } else if (a!=0 && b!=0) {
            return min(a, b);
        }
    } else if (to<=mid) {
        return getValue(from, to, nodeNum*2);
    } else if (from>mid) {
        return getValue(from, to, nodeNum*2+1);
    }
    return -1;
}

int main(void) {
    int N, input;
    int result = 0;
    scanf("%d", &N);

    for (int i=1; i<=N; i++) {
        scanf("%d", &input);
        checker[input] = i;
    }

    for (int i=0; i<2; i++) {
        for (int j=1; j<=N; j++) {
            scanf("%d", &input);
            nodes[checker[input]].val[i] = j;
        }
    }

    makeTree(N);

    for (int i=1; i<=N; i++) {
        int val = getValue(powTwo(logN(N))+0, powTwo(logN(N))+nodes[i].val[0]-1, 1);
        if (val==0) {
            result++;
        } else if (val > nodes[i].val[1]) {
            result++;
        }
        update(powTwo(logN(N))-1+nodes[i].val[0], nodes[i].val[1]);
    }
    printf("%d", result);
    return 0;
}