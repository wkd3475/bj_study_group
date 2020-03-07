#include <cstdio>
#include <string>

struct Trie {
    int finish;
    Trie *next[10];
};


Trie root;

int c2i(char c) {
    return c-'0';
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

int dfs(Trie *t) { 
    for (int i=0; i<10; i++) {
        if (t->next[i]!=NULL) {
            if (t->finish == true) {
                return 1;
            } else {
                if (dfs(t->next[i])) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(void) {
    int t, n;
    char number[11];
    scanf("%d", &t);
    while (t--) {
        root.finish=false;
        for (int i=0; i<10; i++) {
            root.next[i] = NULL;
        }
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%s", number);
            insert(&root, number);
        }
        if(dfs(&root)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}