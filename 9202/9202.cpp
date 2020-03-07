#include <cstdio>
#include <string>

struct Trie {
    int finish;
    Trie *next[26];
};

Trie root;
char boggle[4][4];
int isVisited[4][4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int c2i(char c) {
    return c-'A';
}

void insert(Trie *t, char *number) {
    if (*number=='\0') {
        t->finish = true;
        return;
    }
    if (t->next[c2i(number[0])] == NULL) {
        t->next[c2i(number[0])] = (Trie*)malloc(sizeof(Trie));
        insert(t->next[c2i(number[0])], number+1);
    } else {
        insert(t->next[c2i(number[0])], number+1);
    }
}

int dfs(Trie *t, int x, int y, int testcase) { 
    isVisited[y][x] = testcase;
    (t->next[c2i(boggle[y][x])] != NULL)
    return 0;
}

int main(void) {
    int w, b;
    char words[9];
    scanf("%d", &w);
    for (int i=0; i<w; i++) {
        scanf("%s", words);
        insert(&root, words);
    }

    scanf("%d", &b);
    for (int i=1; i<=b; i++) {
        for (int y=0; y<4; y++) {
            scanf("%s", boggle[y]);
        }

        for (int y=0; y<4; y++) {
            for (int x=0; x<4; x++) {
                isVisited[y][x] = 16*(i-1)+x+1+4*(y);
                if (root.next[c2i(boggle[y][x])] != NULL) {
                    dfs(root.next[c2i(boggle[y][x])], x, y, 16*(i-1)+x+1+4*(y));
                }
            }
        }
    }

    return 0;
}