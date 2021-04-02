#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Print root last post order traversal
void postOrder(Node * root){
    if (root == NULL){
        return; // move up a level
    }
    // going down a level    
    postOrder(root->l);
    // coming up a level    

    // go down a level    
    postOrder(root->r);    
    // come up a level    

    printf("%d ", root->identifier);    

    // beginning the process of moving up
}

int isGreater(int a, int b){
    int ret;
    if (a >= b){
        ret = a;
    }
    else ret = b;
    return ret;
}

int simulate(Node * root, int * skillArr, int * position){
    int ret;
    if (root == NULL){
        ret = skillArr[*position];

        position++;
        printf("Position is %i \n", *position);
        return ret;
    }
    root->victor = isGreater(simulate(root->l, skillArr, position),simulate(root->r, skillArr, position));
    printf("node %i's victor is %i\n", root->identifier, root->victor);
    return root->victor;
}

int main(){

    int numPlayers, skill, tableVal;
    int *tableArr, *skillArr, * position;
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
    return 0;
}