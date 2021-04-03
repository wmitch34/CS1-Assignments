#include <stdio.h>
#include <stdlib.h>
//Program that simulates a single elimination tournament running
//in a bst. Output represents an 'excitement' level. Basic BST
//functions come from Dr. Meade's example code, unique functions are 
//my own.
//Will Mitchell CS1 April 2021

//global var tracks number of null nodes reached in bst
long long int counter = 0;

typedef struct Node Node;
struct Node{
    long long int identifier;
    long long int victor;
    long long int excitement;    
    Node *l, * r;
};

//returns new node
Node * createNode(long long int identifier){
    Node * ret = calloc(1, sizeof(Node));
    ret->identifier = identifier;
    ret->r = ret->l = NULL; 
    return ret;
}

//returns the root of the tree
Node * insert(Node * root, long long int identifier){
    if (root == NULL){
        return createNode(identifier);
    }
    //Don't add duplicates (optional)
    if (root->identifier == identifier){
        return root;   
    }    
    //root is smaller than our target    
    if (root->identifier < identifier){
        root->r = insert(root->r, identifier);
    }
    //root is larger than our target
    else{
        root->l = insert(root->l, identifier);
    }    
    return root;
}

//returns larger of two ints
long long int isGreater(long long int a, long long int b){
    long long int ret;
    if (a >= b){
        ret = a;
    }
    else ret = b;
    return ret;
}

//assign stucts a victor and excitement level
long long int simulate(Node * root, long long int * skillArr){
    //if root is null, pull skill from array and return it
    if(root == NULL){
        long long int tmp = skillArr[counter];
        counter++;
        return tmp;
    }
    //recursive calls return skill levels of children's winner
    long long int a = simulate(root->l, skillArr);
    long long int b = simulate(root->r, skillArr);

    //calculate winner
    root->victor = isGreater(b, a);

    //calculate excitement
    root->excitement = abs(a - b);

    return root->victor; 
}

//calculater total tournament excitement lvl
long long int getExcitement(Node * root, long long int excitement){
    //if NULL, there's no excitement
    if (root == NULL){
        return 0;
    }
    //excitement is the sum of curr root's excitement, and excitement of children
    excitement = root->excitement + getExcitement(root->l, root->excitement) + getExcitement(root->r, root->excitement);

    return excitement;
}

//free all memory other than long long int arrays in main
void destroyTree(Node * root){
    if (root == NULL){
        return;
    }
    destroyTree(root->l);
    destroyTree(root->r);
    free(root);
}

int main(){
    long long int numPlayers;
    long long int *tableArr, *skillArr;
    Node * root = NULL;
      
    scanf("%lli", &numPlayers);

    //unique case for boring 1 player tournaments
    if(numPlayers == 1){
        printf("%i\n", 0);
        return 0;
    }
    
    tableArr = (long long int*)calloc(numPlayers - 1, sizeof(long long int));
    skillArr = (long long int*)calloc(numPlayers, sizeof(long long int));

    //fill table activation arr in post order
    for(long long int i = numPlayers - 2 ; i >= 0; i--){
        scanf("%lli", &tableArr[i]);
    }
    //insert table identifiers into bst
    for(long long int i = 0; i < numPlayers - 1; i++){
        root = insert(root, tableArr[i]);
    }
    //fill player skill arr
    for(long long int i = 0; i < numPlayers; i++){
        scanf("%lli", &skillArr[i]);
    }
    //tournament simulate function returns
    //skill of winner, but parameters of assignment
    //dictate we dont need to do anything with it
    long long int winner = simulate(root, skillArr);

    //get excitment of tournament, excitement starts at 0
    printf("%lli\n", getExcitement(root, 0));

    //free all memory
    destroyTree(root);
    free(tableArr);
    free(skillArr);

    return 0; 
}