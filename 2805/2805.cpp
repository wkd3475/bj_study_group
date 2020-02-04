#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree;

long long getValue(int h) {
    long long sum = 0;
    for (vector<int>::iterator iter=tree.begin(); iter<tree.end(); iter++) {
        if ((*iter)>h) {
            sum += (*iter)-h;
        }
    }
    return sum;
}

int binarySearch(int value, int maxH) {
    int front = 0;
    int end = maxH;

    while(end>front) {
        long long sum = getValue((front+end)/2);
        if (sum<value) {
            end = (front+end)/2;
        }

        if (sum>value) {
            front = (front+end)/2 + 1;
        }

        if (sum==value) {
            return (front+end)/2;
        }
    }
    
    return front-1;
}

int main(void) {
    int N, M, input;
    scanf("%d %d", &N, &M);
    while (N--) {
        scanf("%d", &input);
        tree.push_back(input);
    }

    sort(tree.begin(), tree.end());

    printf("%d", binarySearch(M, tree.back()));

    return 0;
}