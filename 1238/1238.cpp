#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

int N, M, X;
int input[3];
vector<pair<int, int> > city[1001];
int isVisted[1001];

struct Vertex {
    int dist;
    int index;
    Vertex(int value, int d):dist(d), index(value) {}
};

struct cmp {
    bool operator() (Vertex v, Vertex u) {
        return v.dist > u.dist;
    }
};

int main(void) {
    scanf("%d %d %d", &N, &M, &X);

    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &input[0], &input[1], &input[2]);
        
    }
    return 0;
}