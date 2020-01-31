#include <cstdio>
#include <map>
#define BLANK 0b0000
#define UP 0b0001
#define RIGHT 0b0010
#define DOWN 0b0100
#define LEFT 0b1000

using namespace std;

map<char, int> blocks;
char arr[30][30];
bool visit[30][30];
int row, col;
int M[2] = {0,};

int dir[4] = {RIGHT, DOWN, LEFT, UP};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int result_xy[2];
int result_xy2[2];
int result_block_id = 0;
int result_block_id2 = 0;
char result_block;
char result_block2;
int checker = false;

void dps(int x, int y, int come);

bool test(int x, int y, int come);

int main(void) {
    blocks.insert(make_pair('M', UP+DOWN+LEFT+RIGHT));
    blocks.insert(make_pair('Z', UP+DOWN+LEFT+RIGHT));
    blocks.insert(make_pair('.', BLANK));
    blocks.insert(make_pair('|', UP+DOWN));
    blocks.insert(make_pair('-', LEFT+RIGHT));
    blocks.insert(make_pair('+', UP+DOWN+LEFT+RIGHT));
    blocks.insert(make_pair('1', DOWN+RIGHT));
    blocks.insert(make_pair('2', UP+RIGHT));
    blocks.insert(make_pair('3', UP+LEFT));
    blocks.insert(make_pair('4', DOWN+LEFT));
    
    scanf("%d %d", &row, &col);
    fflush(stdin);
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            arr[i][j] = getchar();

            if (arr[i][j]=='M') {
                M[0] = i;
                M[1] = j;
            }
        }
        fflush(stdin);
    }
    // printf("x : %d\n", M[1]+1);
    // printf("y : %d\n", M[0]+1);

    for (int i=0; i<4; i++) {
        if (M[0]+dy[i]<0||M[0]+dy[i]>=row) {
            continue;
        }
        if (M[1]+dx[i]<0||M[1]+dx[i]>=col) {
            continue;
        }
        if (arr[M[0]+dy[i]][M[1]+dx[i]]!='.') {
            dps(M[1]+dx[i], M[0]+dy[i], dir[i]);
        }
    }

    if (!checker) {
        for (int i=0; i<4; i++) {
            if (M[0]+dy[i]<0||M[0]+dy[i]>=row)
                continue;
            if (M[1]+dx[i]<0||M[1]+dx[i]>=col)
                continue;
            if (test(M[1]+dx[i], M[0]+dy[i], dir[i]))
                break;
        }
    }

    if (!checker) {
        printf("%d %d %c\n", result_xy2[0]+1, result_xy2[1]+1, result_block2);
    } else {
        printf("%d %d %c\n", result_xy[0]+1, result_xy[1]+1, result_block);
    }
    
    return 0;
};

bool test(int x, int y, int come) {
    // printf("test!\n");
    result_block_id |= (come*4)%15;
    for (int i=0; i<4; i++) {
        if (y+dy[i]<0||y+dy[i]>=row)
            continue;
        if (x+dx[i]<0||x+dx[i]>=col)
            continue;

        if (blocks[arr[y+dy[i]][x+dx[i]]]&dir[(i+2)%4]) {
            if (arr[y+dy[i]][x+dx[i]]=='Z' || arr[y+dy[i]][x+dx[i]]=='M')
                continue;

            result_block_id |= dir[i];
        }
    }
    map<char, int>::iterator it;
    for (it=blocks.begin(); it!=blocks.end(); it++) {
        if (it->second == result_block_id) {
            result_block = it->first;
            result_xy[0] = y;
            result_xy[1] = x;
            // printf("result_block_id : %d\n", result_block_id);
            checker = true;
            return true;
        }
    }
    result_block_id = 0;
    return false;
}

void dps(int x, int y, int come) {
    visit[y][x] = true;
    // printf("visited : %d %d\n", x, y);
    if (arr[y][x] == 'Z') {
        return;
    }

    if (arr[y][x] == '.') {
        for (int i=0; i<4; i++) {
            if (y+dy[i]<0||y+dy[i]>=row)
                continue;
            if (x+dx[i]<0||x+dx[i]>=col)
                continue;

            if (blocks[arr[y+dy[i]][x+dx[i]]]&dir[(i+2)%4]) {
                if (arr[y+dy[i]][x+dx[i]]=='M')
                    continue;
                if (arr[y+dy[i]][x+dx[i]]=='Z') {
                    result_block_id2 |= (come*4)%15;
                    for (int i=0; i<4; i++) {
                        if (y+dy[i]<0||y+dy[i]>=row)
                            continue;
                        if (x+dx[i]<0||x+dx[i]>=col)
                            continue;

                        if (blocks[arr[y+dy[i]][x+dx[i]]]&dir[(i+2)%4]) {
                            if (arr[y+dy[i]][x+dx[i]]=='Z' || arr[y+dy[i]][x+dx[i]]=='M')
                                continue;

                            result_block_id2 |= dir[i];
                        }
                    }

                    map<char, int>::iterator it;
                    for (it=blocks.begin(); it!=blocks.end(); it++) {
                        if (it->second == result_block_id2) {
                            result_block2 = it->first;
                            result_xy2[0] = y;
                            result_xy2[1] = x;
                            // printf("result_block_id2 : %d\n", result_block_id2);
                        }
                    }
                }

                result_block_id |= dir[i];
            }
        }

        map<char, int>::iterator it;
        for (it=blocks.begin(); it!=blocks.end(); it++) {
            if (it->second == result_block_id) {
                result_block = it->first;
                result_xy[0] = y;
                result_xy[1] = x;
                checker = true;
                // printf("result_block_id : %d\n", result_block_id);
                return;
            }
        }
        result_block_id = 0;
    } else {
        for (int i=0; i<4; i++) {
            if (dir[i]&blocks[arr[y][x]] && (come!=dir[(i+2)%4])) {
                if (y+dy[i]<0||y+dy[i]>=row)
                    continue;
                if (x+dx[i]<0||x+dx[i]>=col)
                    continue;
                if (visit[y+dy[i]][x+dx[i]])
                    continue;
                dps(x+dx[i], y+dy[i], dir[i]);
            }
        }
    }
    
    return;
};