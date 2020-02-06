#include <cstdio>
#include <set>
using namespace std;

typedef struct node {
    int num;
    int val[3];
} Node;

Node nodes[500001];

set<int> s;

int main(void) {
    int N, input;
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        nodes[i].num = i;
    }

    for (int i=0; i<3; i++) {
        for (int j=1; j<=N; j++) {
            scanf("%d", &input);
            nodes[input].val[i] = j;
        }
    }

    for (int i=1; i<=N; i++) {
        int flag = false;
        Node node;
        for (set<int>::iterator iter=s.begin(); iter!=s.end(); iter++) {
            if (nodes[*iter].val[0]>nodes[i].val[0] && nodes[*iter].val[1]>nodes[i].val[1] && nodes[*iter].val[2]>nodes[i].val[2]) {
                s.erase(iter);
                continue;
            }

            if (nodes[*iter].val[0]<nodes[i].val[0] && nodes[*iter].val[1]<nodes[i].val[1] && nodes[*iter].val[2]<nodes[i].val[2]) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            s.insert(nodes[i].num);
        }
    }

    printf("%lu\n", s.size());
    
    return 0;
}