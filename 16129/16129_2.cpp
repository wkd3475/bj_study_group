#include <cstdio>

int R, C;
int arr[21][21];
int total = 0;
int score[4][4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ddururu[5] = {1, 0, 0, 1, 0};

struct Area {
    int start_x;
    int start_y;
    int end_x;
    int end_y;
};

void dfs(int y, int x, int d, int originY, int originX, int beforeY, int beforeX, int scoreA, int scoreB);

void solve(Area *search, int scoreA, int scoreB);

int checkArea(Area *area, int y, int x);

void dfs2(int y, int x, int d, int originY, int originX, int beforeY, int beforeX, int scoreA, int scoreB) {
    if (arr[y][x] != ddururu[d])
        return;
        
    if (d==4) {
        score[scoreA][scoreB]++;
        total++;
        return;
    }

    int nextX, nextY;
    for (int i=0; i<4; i++) {
        nextX = x+dx[i];
        nextY = y+dy[i];

        if (nextX<1||nextX>C)
            continue;
        if (nextY<1||nextY>R)
            continue;
        if (nextX==beforeX&&nextY==beforeY)
            continue;
        if (nextX==originX&&nextY==originY)
            continue;

        if (arr[nextY][nextX] == ddururu[d+1])
            dfs2(y+dy[i], x+dx[i], d+1, originY, originX, y, x, scoreA, scoreB);
    }
}

Area* newArea(int _start_x, int _start_y, int _end_x, int _end_y) {
    Area* area = new Area;
    area->start_x = _start_x;
    area->start_y = _start_y;
    area->end_x = _end_x;
    area->end_y = _end_y;
    return area;
}

int main(void) {
    scanf("%d %d", &R, &C);

    for (int i=1; i<=20; i++) {
        for (int j=1; j<=20; j++) {
            if (((i-1)*C+j-1)%5==0 || ((i-1)*C+j-1)%5==3)
                arr[i][j] = 1;
            else 
                arr[i][j] = 0;
        }
    }

    Area *s = newArea(1, 1, C, R);
    for (int i=s->start_y; i<=s->end_y; i++) {
        for (int j=s->start_x; j<=s->end_x; j++) {
            printf("%d %d\n", i, j);
            dfs2(i, j, 0, i, j, -1, -1, 0, 0);
        }
    }
    printf("%d\n", total);

    score[0][0] = 0;
    total = 0;

    if (R>20 && C>20) {
        Area *bg[4][4];
        Area *s[4][4];

        s[0][0] = newArea(1, 1, 5, 5);
        bg[0][0] = newArea(1, 1, 10, 10);
        s[0][1] = newArea(6, 1, 10, 5);
        bg[0][1] = newArea(1, 1, 15, 10);
        s[0][2] = newArea(11, 1, 15, 5);
        bg[0][2] = newArea(6, 1, 15+C%5, 10);
        s[0][3] = newArea(16, 1, 15+C%5, 10);
        bg[0][3] = newArea(11, 1, 15+C%5, 10);
        s[1][0] = newArea(1, 6, 5, 10);
        bg[1][0] = newArea(1, 1, 10, 15);
        s[1][1] = newArea(6, 6, 10, 10);
        bg[1][1] = newArea(1, 1, 15, 15);
        s[1][2] = newArea(11, 6, 15, 10);
        bg[1][2] = newArea(6, 1, 15+C%5, 15);
        s[1][3] = newArea(16, 6, 15+C%5, 15);
        bg[1][3] = newArea(11, 1, 15+C%5, 15);
        s[2][0] = newArea(1, 11, 5, 15);
        bg[2][0] = newArea(1, 6, 10, 15+R%5);
        s[2][1] = newArea(6, 11, 10, 15);
        bg[2][1] = newArea(1, 6, 15, 15+R%5);
        s[2][2] = newArea(11, 11, 15, 15);
        bg[2][2] = newArea(6, 6, 15+C%5, 15+R%5);
        s[2][3] = newArea(16, 11, 15+C%5, 15);
        bg[2][3] = newArea(11, 6, 15+C%5, 15+R%5);
        s[3][0] = newArea(1, 16, 5, 15+R%5);
        bg[3][0] = newArea(1, 11, 10, 15+R%5);
        s[3][1] = newArea(6, 16, 10, 15+R%5);
        bg[3][1] = newArea(1, 11, 15, 15+R%5);
        s[3][2] = newArea(11, 16, 15, 15+R%5);
        bg[3][2] = newArea(6, 11, 15+C%5, 15+R%5);
        s[3][3] = newArea(16, 16, 15+C%5, 15+R%5);
        bg[3][3] = newArea(11, 11, 15+C%5, 15+R%5);

        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                solve(s[i][j], i, j);
            }
        }

        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                printf("(%d %d):%d\n", i, j, score[i][j]);
            }
        }

        total = score[0][0] + (C-10)/5*score[0][1] + score[0][2] + score[0][3] +
            (R-10)/5*score[1][0] + ((R-10)/5)*((C-10)/5)*score[1][1] + (R-10)/5*score[1][2] + (R-10)/5*score[1][3] +
            score[2][0] + (C-10)/5*score[2][1] + score[2][2] + score[2][3] +
            score[3][0] + (C-10)/5*score[3][1] + score[3][2] + score[3][3];
        printf("%d\n", total);
    } else {
        Area *bg = newArea(1, 1, C, R);
        Area *s = newArea(1, 1, C, R);
        solve(s, 0, 0);
        printf("%d\n", total);
    }

    return 0;
}

void dfs(int y, int x, int d, int originY, int originX, int beforeY, int beforeX, int scoreA, int scoreB) {
    if (arr[y][x] != ddururu[d])
        return;
        
    if (d==4) {
        score[scoreA][scoreB]++;
        total++;
        return;
    }

    int nextX, nextY;
    for (int i=0; i<4; i++) {
        nextX = x+dx[i];
        nextY = y+dy[i];

        if (nextX<1||nextX>15+C%5)
            continue;
        if (nextY<1||nextY>15+R%5)
            continue;
        if (nextX==beforeX&&nextY==beforeY)
            continue;
        if (nextX==originX&&nextY==originY)
            continue;

        if (arr[nextY][nextX] == ddururu[d+1])
            dfs(y+dy[i], x+dx[i], d+1, originY, originX, y, x, scoreA, scoreB);
    }
}

void solve(Area *search, int scoreA, int scoreB) {
    for (int i=search->start_y; i<=search->end_y; i++) {
        for (int j=search->start_x; j<=search->end_x; j++) {
            dfs(i, j, 0, i, j, -1, -1, scoreA, scoreB);
        }
    }
}