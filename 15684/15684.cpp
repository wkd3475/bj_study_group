#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, M, H;
int a, b;
int ladder[32][12];
int zero_size;
int min_val=123456789;
vector<pair<int, int> > zero;

int down(int start) {
    int now = start;
    for (int i=1; i<=H; i++) {
        if (ladder[i][now])
            now++;
        else if (ladder[i][now-1])
            now--;
    }

    if (now == start)
        return true;
    return false;
}

int check_downs() {
    for (int i=1; i<=N; i++) {
        if (down(i)==false)
            return false;
    }
    return true;
}

int make_line(int index, int count) {
    int result = 0;
    if (ladder[zero[index].first][zero[index].second+1]==1
        || ladder[zero[index].first][zero[index].second-1]==1)
        return 0;

    ladder[zero[index].first][zero[index].second] = 1;

    if (check_downs()) {
        ladder[zero[index].first][zero[index].second] = 0;
        return count;
    }
    
    if (count == 4) {
        ladder[zero[index].first][zero[index].second] = 0;
        return 0;
    }

    for (int i=index+1; i<zero_size; i++) {
        int val = make_line(i, count+1);
        if (result == 0)
            result = val;
        else if (val != 0)
            result = min(val, result);
    }
    ladder[zero[index].first][zero[index].second] = 0;
    return result;
}

int main(void) {
    scanf("%d %d %d", &N, &M, &H);
    printf("M : %d\n", M);
    for (int i=1; i<=M; i++) {
        printf("i : %d\n", i);
        scanf("%d %d", &a, &b);
        ladder[a][b] = 1;
    }

    for (int i=1; i<=H; i++) {
        for (int j=1; j<=N-1; j++) {
            if (ladder[i][j]==0) {
                zero.push_back(make_pair(i, j));
            }
        }
    }
    zero_size = zero.size();

    if (check_downs()) {
        printf("0");
        return 0;
    }

    for (int i=0; i<zero_size; i++) {
        if (int result = make_line(i, 1)) {
            if (min_val > result) {
                min_val = result;
            }
        }
    }

    if (min_val == 123456789)
        printf("-1");
    else
        printf("%d", min_val);
    

    return 0;
}