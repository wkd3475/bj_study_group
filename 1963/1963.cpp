#include <cstdio>
#include <queue>
using namespace std;

int isPrime[10000];
int isVisited[10000];
int T;
int A, B;
int testcase;
queue<pair<int, int> > bfs_queue;

void makePrime() {
    for (int i=1000; i<10000; i++) {
        for (int j=2; j*j<=i; j++) {
            if (i%j==0) {
                isPrime[i] = 1;
            }
        }
        isPrime[i] = !isPrime[i];
    }
}

int pow10(int n) {
    int result = 1;
    while (n>0) {
        result *= 10;
        n--;
    }
    return result;
}

int bfs() {
    pair<int, int> front;
    int value[4];
    while (!bfs_queue.empty()) {
        front = bfs_queue.front();
        if (front.first == B) {
            return front.second;
        }
        value[3] = front.first%1000;
        value[2] = front.first%100 + (front.first/1000)*1000;
        value[1] = front.first%10 + (front.first/100)*100;
        value[0] = (front.first/10)*10;
        for (int j=0; j<4; j++) {
            for (int k=0; k<10; k++) {
                if (isPrime[value[j]+k*pow10(j)]==1 && isVisited[value[j]+k*pow10(j)]!=testcase) {
                    bfs_queue.push(make_pair(value[j]+k*pow10(j), front.second+1));
                    isVisited[value[j]+k*pow10(j)] = testcase;
                }
            }
        }
        bfs_queue.pop();
    }
    return -1;
}

int main(void) {
    int result;
    makePrime();
    scanf("%d", &T);

    for (testcase=1; testcase<=T; testcase++) {
        scanf("%d %d", &A, &B);
        isVisited[A] = testcase;
        bfs_queue.push(make_pair(A, 0));
        result = bfs();
        if (result == -1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", result);
        }

        while (!bfs_queue.empty()) {
            bfs_queue.pop();
        }
    }
    
    return 0;
}