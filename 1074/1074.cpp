#include <cstdio>
#include <cmath>

using namespace std;

int getValue(int N, int r, int c) {
    if (N==1) {
        if (r==0 && c==0) return 0;
        else if (r==0 && c==1) return 1;
        else if (r==1 && c==0) return 2;
        else if (r==1 && c==1) return 3;
    }

    int mid = pow(2, N-1);
    if (r<mid && c<mid) {
        return getValue(N-1, r, c);
    } else if (r>=mid && c<mid) {
        return 2*pow(mid, 2) + getValue(N-1, r-mid, c);
    } else if (r<mid && c>=mid) {
        return pow(mid, 2) + getValue(N-1, r, c-mid);
    } else {
        return 3*pow(mid, 2) + getValue(N-1, r-mid, c-mid);
    }
}

int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);

    printf("%d\n", getValue(N, r, c));
    return 0;
}