#include "func.h"

int main(){
    Node *root = NULL;
    int rc;

    while (rc = dialog(msgs, NMsgs)){
        if (rc == 0)
        break;

        if(rc == 1)
        root = T_Add(root);

	if(rc == 2)
	T_Show("", root, 0);

	if(rc == 3){
	    Node *ptr = T_Find(root);
	    if(ptr)
            printf("key: %d | info: %s\n", ptr->key, ptr->info);
            else
            printf("Key was not found\n");
	}

	if(rc == 4){
	    post(root);
	    printf("\n");
	}

	if(rc == 5){
	    Node *ptr = max(root);
            if(ptr)
            printf("key: %d | info: %s\n", ptr->key, ptr->info);
            else
            printf("Key doesnt exist\n");
        }
    }
    printf("That's all. Bye!\n");
    clear(root);
    return 0;
}

