#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> test;

int binarySearch(int value, int len) {
    int front = 0;
    int end = len-1;

    while(end>=front) {
        if (v[(front+end)/2]<value) {
            front = (front+end)/2 + 1;
        }

        if (v[(front+end)/2]>value) {
            end = (front+end)/2 - 1;
        }

        if (v[(front+end)/2]==value) {
            return 1;
        }
    }
    
    return 0;
}

int main(void) {
    int N, M, input;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    scanf("%d", &M);
    while (M--) {
        scanf("%d", &input);
        test.push_back(input);
    }

    for (vector<int>::iterator iter=test.begin(); iter<test.end(); iter++) {
        printf("%d ", binarySearch((*iter), v.size()));
    }

    return 0;
}