#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<pair<int, int> > edges[10001];
queue<int> q;
int isVisited[10001];

int bfs(int from, int to, int weight, int testNum) {
    while (!q.empty()) {
        q.pop();
    }

    int front;
    q.push(from);
    isVisited[from] = testNum;
    while (!q.empty()) {
        front = q.front();
        for (vector<pair<int, int> >::iterator iter=edges[front].begin(); iter<edges[front].end(); iter++) {
            if ((*iter).first == to && (*iter).second >= weight) {
                return 1;
            }
            if ((*iter).second >= weight && isVisited[(*iter).first]!=testNum) {
                q.push((*iter).first);
                isVisited[(*iter).first] = testNum;
            }
        }
        q.pop();
    }
    return 0;
}

int binarySearch(int maxWeight, int from, int to) {
    int front = 0;
    int end = maxWeight;
    int testNum = 1;

    while(end>=front) {
        int mid = (front+end)/2;
        if (bfs(from, to, mid, testNum)) {
            front = (front+end)/2+1;
        } else {
            end = (front+end)/2-1;
        }
        testNum++;
    }
    
    return front-1;
}

int main(void) {
    int N, M, input[3];
    int from, to;
    int max=0;
    scanf("%d %d", &N, &M);
    while (M--) {
        scanf("%d %d %d", &input[0], &input[1], &input[2]);
        edges[input[0]].push_back(make_pair(input[1], input[2]));
        edges[input[1]].push_back(make_pair(input[0], input[2]));
        if (max<input[2]) {
            max = input[2];
        }
    }
    scanf("%d %d", &from, &to);
    printf("%d", binarySearch(max, from, to));

    return 0;
}