#include <cstdio>
#include <vector>
using namespace std;

int N, M;
int max_zero;
int block_map[9][9];
int copied_map[9][9];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int max_val=0;
vector<pair<int, int> > zero, virus;

void copy_map() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            copied_map[i][j] = block_map[i][j];
        }
    }
}

void make_virus(int y, int x) {
    for (int i=0; i<4; i++) {
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        
        if (nextY>=N || nextY<0)
            continue;
        if (nextX>=M || nextX<0)
            continue;
        if (copied_map[nextY][nextX] == 0) {
            copied_map[nextY][nextX] = 2;
            make_virus(nextY, nextX);
        }
    }
}

int get_result() {
    int result=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (copied_map[i][j]==0) {
                result++;
            }
        }
    }
    return result;
}

void make_wall(int index, int num) {
    block_map[zero[index].first][zero[index].second] = 1;
    if (num==3) {
        copy_map();
        for (pair<int, int> v : virus) {
            make_virus(v.first, v.second);
        }

        int result = get_result();
        
        if (result > max_val) {
            max_val = result;
        }

        block_map[zero[index].first][zero[index].second] = 0;
        return;
    }

    for (int i=index+1; i<max_zero; i++) {
        make_wall(i, num+1);
    }
    
    block_map[zero[index].first][zero[index].second] = 0;
}

int main(void) {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &block_map[i][j]);
            if (block_map[i][j] == 2)
                virus.push_back(make_pair(i, j));
            else if (block_map[i][j] == 0)
                zero.push_back(make_pair(i, j));
        }
    }

    max_zero = zero.size();

    for (int i=0; i<max_zero; i++) {
        make_wall(i, 1);
    }

    printf("%d", max_val);
    
    return 0;   
}