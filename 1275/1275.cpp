#include <cstdio>

typedef struct node {
    long long val;
    int rightCover;
    int leftCover;
} Node;

Node nodes[1<<20];

int getH(int n) {
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

void change(long long a, long long b, int n) {
    int now = powTwo(getH(n))-2+a;
    long long dif = b - nodes[now].val;
    
    for (int i=0; i<getH(n)+1; i++) {
        nodes[now].val += dif;
        now = (now-1)/2;
    }
}

long long getValue(int from, int to, int nodeNum) {
    int mid = (nodes[nodeNum].rightCover + nodes[nodeNum].leftCover)/2;

    if (nodes[nodeNum].leftCover==from && nodes[nodeNum].rightCover==to) {
        return nodes[nodeNum].val;
    }

    if (from<=mid && to>mid) {
        return getValue(from, mid, nodeNum*2+1) + getValue(mid+1, to, nodeNum*2+2);
    } else if (to<=mid) {
        return getValue(from, to, nodeNum*2+1);
    } else if (from>mid) {
        return getValue(from, to, nodeNum*2+2);
    }
    return -1;
}

int main(void) {
    int N, Q;
    int a, b, c, d;
    scanf("%d %d", &N, &Q);

    for (int i=0; i<N; i++) {
        scanf("%lld", &nodes[powTwo(getH(N))-1+i].val);
    }

    for (int i=0; i<powTwo(getH(N)); i++) {
        nodes[powTwo(getH(N))-1+i].rightCover = powTwo(getH(N))-1+i;
        nodes[powTwo(getH(N))-1+i].leftCover = powTwo(getH(N))-1+i;
    }

    for (int i=getH(N)-1; i>=0; i--) {
        for (int j=0; j<powTwo(i); j++) {
            nodes[powTwo(i)-1+j].val=nodes[(powTwo(i)-1+j)*2+1].val+nodes[(powTwo(i)-1+j)*2+2].val;
            nodes[powTwo(i)-1+j].leftCover = nodes[(powTwo(i)-1+j)*2+1].leftCover;
            nodes[powTwo(i)-1+j].rightCover = nodes[(powTwo(i)-1+j)*2+2].rightCover;
        }
    }

    for (int i=0; i<Q; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a = powTwo(getH(N))-2+a;
        b = powTwo(getH(N))-2+b;
        if (a<b)
            printf("%lld\n", getValue(a, b, 0));
        else {
            printf("%lld\n", getValue(b, a, 0));
        }
        change(c, d, N);
    }
    return 0;
}