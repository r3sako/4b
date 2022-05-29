#include "func.h"

Node *new(int key, char *info){
    Node *myNode = (Node *) malloc(sizeof(Node));
    myNode->info = malloc(sizeof(char)*strlen(info)+1);
    strcpy(myNode->info,info);
    myNode->left = myNode->right = NULL;
    myNode->key = key;
    myNode->color = 1;

    return myNode;
}

Node *rotateLeft(Node *myNode){

    printf("left rotation!!\n");

    Node *child = myNode->right;
    Node *childLeft = child->left;
    child->left = myNode;
    myNode->right = childLeft;

    return child;
}

Node *rotateRight(Node *myNode){

    printf("right rotation\n");

    Node *child = myNode->left;
    Node *childRight =  child->right;
    child->right = myNode;
    myNode->left = childRight;

    return child;
}

int isRed(Node *myNode){

    if (myNode == NULL)
    return 0;

    return (myNode->color == 1);
}

void swap(Node *node1, Node *node2){

    int temp = node1->color;

    node1->color = node2->color;
    node2->color = temp;
}

Node *insert(Node *myNode, int key, char *info){

    if (myNode == NULL)
        return new(key, info);

    if (key < myNode->key)
    myNode->left = insert(myNode->left, key, info);

    else if (key > myNode->key)
    myNode->right = insert(myNode->right, key, info);

    else
    return myNode;

    if (isRed(myNode->right) && !isRed(myNode->left)){
        myNode = rotateLeft(myNode);
        swap(myNode, myNode->left);
    }
    if (isRed(myNode->left) && isRed(myNode->left->left)){
        myNode = rotateRight(myNode);
        swap(myNode, myNode->right);
    }
    if (isRed(myNode->left) && isRed(myNode -> right)){
        myNode->color = !myNode->color;
        myNode->left->color = 0;
        myNode->right->color = 0;
    }
    return myNode;
}

