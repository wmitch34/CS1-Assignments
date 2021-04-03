#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter = 0;

typedef struct Node Node;

struct Node{
    int identifier;
    int victor;    
    Node *l, * r;
};

Node * createNode(int identifier){
    Node * ret = calloc(1, sizeof(Node));
    ret->identifier = identifier;
    ret->r = ret->l = NULL; 
    return ret;
}

// Return the root of the tree
Node * insert(Node * root, int identifier){
    if (root == NULL){
        return createNode(identifier);
    }
    // Don't add duplicates (optional)
    if (root->identifier == identifier){
        return root;   
    }    
    // root is smaller than our target    
    if (root->identifier < identifier){
        root->r = insert(root->r, identifier);
    }
    else{
        root->l = insert(root->l, identifier);
    }    
    return root;
}

void postOrder(Node * root){
    if (root == NULL){
        return;
    }

    postOrder(root->l);
    postOrder(root->r);    
    printf("%d ", root->identifier);    
}

int isGreater(int a, int b){
    int ret;
    if (a >= b){
        ret = a;
    }
    else ret = b;
    return ret;
}

int simulate(Node * root, int * skillArr, int counter){
    if(root == NULL){
        return skillArr[counter++];
    }
    root->victor = isGreater(simulate(root->r, skillArr, counter),simulate(root->l, skillArr, counter));
    printf("Table %i's victor is %i. \n", root->identifier, root->victor);
    return root->victor; 
}

int main(){
    Node * root = NULL;
    int victor;
    //int counter;
    int skillArr[6] = {3, 19, 10, 20, 13, 6};
    int tableArr[5] = {4, 3, 5, 2, 1};

    for(int i = 0; i < 5; i++){
        root = insert(root, tableArr[i]);
    }

    victor = simulate(root, skillArr, counter);
    printf("The Tournament winner is Skill number %i.\n", victor);
    postOrder(root);
    printf("\n");

    return 0;
    /*int numPlayers, skill, tableVal;
    int *tableArr, *skillArr, position;
    Node * root = NULL;
   
    printf("How many palyers?\n");
    scanf("%i", &numPlayers);
    
    tableArr = (int*)calloc(numPlayers - 1, sizeof(int));
    skillArr = (int*)calloc(numPlayers, sizeof(int));

    //get table activation order
    printf("Enter The table activation order\n");
    for(int i = numPlayers - 2 ; i >= 0; i--){
        scanf("%i", &tableVal);
        tableArr[i] = tableVal;
    }
    //insert table identifiers into bst
    for(int i = 0; i < numPlayers - 1; i++){
        root = insert(root, tableArr[i]);
    }
    //get player skill
    printf("Enter player skill:\n");
    for(int i = 0; i < numPlayers; i++){
        scanf("%i", &skill);
        skillArr[i] = skill;
    }
    //run tournament
    simulate(root, skillArr, position);

    printf("\nPost Order:\n");
    postOrder(root);
    printf("\n");
    return 0;*/
}