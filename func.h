#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

const char *msgs[6];
const int NMsgs ;

typedef struct Node{
    struct Node *left;
    struct Node*right;
    char *info;
    int key;
    int color;
} Node;

void clear(Node *node);
Node *max(Node *node);
void post(Node *root);
Node *T_Find(Node *root);
void T_Show(char* prefix, Node* node, int isLeft);
int dialog(const char *msgs[], int N);
int getInt(int *a);
Node *T_Add(Node *root);
Node *insert(Node *myNode, int key, char *info);
void swap(Node *node1, Node *node2);
int isRed(Node *myNode);
Node *rotateRight(Node *myNode);
Node *rotateLeft(Node *myNode);
Node *new(int key, char *info);

