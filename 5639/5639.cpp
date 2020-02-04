#include <cstdio>

typedef struct node {
    int val;
    Node *left;
    Node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

void addNode(BST *bst, Node *root, Node *node) {
    if (bst->root==NULL) {
        bst->root = node;
    }

    if 
}

Node* newNode(int x) {
    Node node;
    node.val = x;
    node.left = NULL;
    node.right = NULL;
}

void getValue(BST *bst) {
    int x;
    Node *node;
    scanf("%d", &x);
    if (x==EOF) {
        return;
    }


    node = newNode(x);
}

int main(void) {
    BST bst;
    bst.root=NULL;
    return 0;
}