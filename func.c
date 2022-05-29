#include "func.h"

const char *msgs[] = {"0. Quit", "1. Add", "2. Show", "3. Find", "4. Post-order", "5. Special F"};
const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

void clear(Node *node){
    if (node == NULL) return;
    clear(node->left);
    clear(node->right);
    printf("%s\n", node->info);
    free(node->info);
    free(node);
}

void post(Node *root){
    if (root) {
        post(root->right);
        post(root->left);
        printf("%d-> ", root->key);
    }
}

Node *max(Node *node){
    if (node){
        if (node->right != NULL)
        return max(node->right);
    }
    return node;
}

Node *T_Find(Node *root){
    int k, n;
    printf("Enter key: ");
    n = getInt(&k);
    if(n==0)
    return NULL;

    while (root != NULL){
        if (root->key > k){
            root = root->left;
        }
        else if (root->key < k){
            root = root->right;
        }
        else{
            return root;
        }
    }
    return root;
}

void T_Show(char* pref, Node *node, int flag){

    if (node) {
        printf("%s", pref);
        if (flag) printf("├──");
        else printf("└──");

        printf("%d(%d)(%s)\n", node->key, node->color, node->info);

        char* n;
        if (flag) n = "│   ";
        else n = "    ";

        int slen = (int) strlen(pref);
        int dlen = (int) strlen(n);
        char* m = (char*) calloc(slen + dlen + 1, sizeof(char));
        memcpy(m, pref, slen+1);
        memcpy(m+slen, n, dlen+1);

        T_Show(m, node->right, 1);
        T_Show(m, node->left, 0);

        free(m);
    }
}


Node *T_Add(Node *root){
    int k, n, rc;
    puts("Enter key: ");
    n = getInt(&k);
    if (n == 0)
	return 0;

    char *info = NULL;
    info = readline("Enter info: ");

    root = insert(root, k, info);
    root->color = 0;
    puts("Ok\n");
    free(info);
    return root;
}

int getInt(int *a){
    int e;

    do{
        e = scanf("%d", a);
        if (e < 0){
            return 0;
        }
        if (e == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (e == 0);
    return 1;
}

int dialog(const char *msgs[], int N){
    char *errmsg = "";
    int rc;
    int i, n;

    for(i = 0; i < N; ++i)
    puts(msgs[i]);

    do{
        puts(errmsg);
        errmsg = "You are wrong. Repeate, please!";
        puts("Make your choice: ");
        n = getInt(&rc);
        if(n == 0)
        rc = 0;
    } while(rc < 0 || rc >= N);

    return rc;
}

