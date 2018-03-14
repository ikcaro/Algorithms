#include <stdio.h>
#include <malloc.h>

#include <queue>
#include <stack>

using namespace std;

typedef struct node {
    int   data;
    struct node *left;
    struct node *right;
} NODE;

NODE *create_node(int val)
{
    NODE *p   = (NODE *)malloc(sizeof(NODE));
    p->data   = val;
    p->left   = NULL;
    p->right  = NULL;

    return p;
}

void tree_init(NODE **root)
{
    *root = NULL;
}


void tree_insert(NODE **root, int val)
{
    if (*root == NULL) {
        *root = create_node(val);
    } else {
        if (val < (*root)->data)
            tree_insert(&((*root)->left), val);
        else
            tree_insert(&((*root)->right), val);
    }
}

void tree_preorder(NODE *root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        tree_preorder(root->left);
        tree_preorder(root->right);
    }
}

void tree_inorder(NODE *root)
{
    if (root != NULL) {
        tree_inorder(root->left);
        printf("%d ", root->data);
        tree_inorder(root->right);
    }
}

void tree_postorder(NODE *root)
{
    if (root != NULL) {
        tree_postorder(root->left);
        tree_postorder(root->right);
        printf("%d ", root->data);
    }
}

void tree_BFS(NODE *root)
{
    NODE *c;
    queue <NODE *> Q;

    Q.push(root);
    while (!Q.empty()) {
        c = Q.front();
        Q.pop();

        printf("%d ", c->data);

        if (c->left != NULL)
            Q.push(c->left);

        if (c->right != NULL)
            Q.push(c->right);
    }
}

void tree_DFS(NODE *root)
{
    NODE *c;
    stack <NODE *> S;

    S.push(root);

    while (!S.empty()) {
        c = S.top();
        S.pop();
        
        printf("%d ", c->data);

        if (c->left != NULL)
            S.push(c->left);

        if (c->right != NULL)
            S.push(c->right);
    }
}

NODE *tree_rsearch(NODE *root, int val)
{
    if (root == NULL || val == root->data)
        return root;

    if (val < root->data)
        return tree_rsearch(root->left, val);
    else 
        return tree_rsearch(root->right, val);

    return NULL;
}

NODE *tree_isearch(NODE *root, int val)
{
    while (root != NULL && val != root->data) {
        if (val < root->data)
            root = root->left;
        else
            root = root->right;
    }
    
    return root;
}

NODE *tree_min(NODE *root)
{
    while (root->left != NULL)
        root = root->left;
    
    return root;
}

NODE *tree_max(NODE *root)
{
    while (root->right != NULL)
        root = root->right;
    
    return root;
}

NODE *tree_successor(NODE *root)
{

}

NODE *tree_predecessor(NODE *root)
{

}

int main()
{
    int i;
    NODE *t;
    NODE *c;

    int v[13] = {6, 4, 9, 2, 5, 7, 10, 1, 3, 8, 12, 22, 100};

    tree_init(&t);
    for (i = 0; i < 13; ++i)
        tree_insert(&t, v[i]);

    printf("PRE-ORDER\n ");
    tree_preorder(t);
    printf("\n\n");

    printf("IN-ORDER\n ");
    tree_inorder(t);
    printf("\n\n");

    printf("POST-ORDER\n ");
    tree_postorder(t);
    printf("\n\n");

    printf("BFS\n ");
    tree_BFS(t);
    printf("\n\n");

    printf("DFS\n ");
    tree_DFS(t);
    printf("\n\n");

    c = tree_rsearch(t, 15);
    if (c != NULL)
        printf("%p %d\n", c, c->data);
    else
        printf("value not found\n");

    c = tree_rsearch(t, 3);
    if (c != NULL)
        printf("%p %d\n", c, c->data);
    else
        printf("value not found\n");

    c = tree_min(t);
    if (c != NULL)
        printf("Min: %p %d\n", c, c->data);
    
    c = tree_max(t);
    if (c != NULL)
        printf("Max: %p %d\n", c, c->data);

    return 0;
}
