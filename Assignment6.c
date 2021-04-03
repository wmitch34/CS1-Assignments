#include <stdio.h>
#include <stdlib.h>

int counter = 0;

typedef struct Node Node;

struct Node{
    int identifier;
    int victor;
    int excitement;    
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
    //root is larger than target
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

//assign stucts a victor and excitement level
int simulate(Node * root, int * skillArr){
    //if root is null, pull skill from array and return it
    if(root == NULL){
        int tmp = skillArr[counter];
        counter++;
        return tmp;
    }
    //recursive calls return skill levels of children's winner
    int a = simulate(root->l, skillArr);
    int b = simulate(root->r, skillArr);

    //calculate winner
    root->victor = isGreater(b, a);

    //calculate excitement
    root->excitement = abs(a - b);
    
    //test output
    printf("Table %i's competitors are %i and %i.\n", root->identifier, a, b);
    printf("Table %i's victor is %i. \n", root->identifier, root->victor);
    printf("Table %i's excitement level is %i.\n\n", root->identifier, root->excitement);
    //return skill of victor
    return root->victor; 
}

int getExcitement(Node * root){
    if (root == NULL){
        return 0;
    }


}

int main(){
    Node * root = NULL;
    int victor;
    //int counter;
    int skillArr[6] = {3, 19, 10, 20, 13, 6};
    int tableArr[5] = {1, 2, 5, 3, 4};

    for(int i = 0; i < 5; i++){
        root = insert(root, tableArr[i]);
    }
    printf("competitor skill levels: ");
    for(int i = 0; i < 6; i++){
        printf("%i ", skillArr[i]);
    }
    printf("\n");
    victor = simulate(root, skillArr);
    printf("The Tournament winner is Skill of  %i.\n", victor);
    printf("Post Order: ");
    postOrder(root);
    printf("\n");

    return 0;
    /*int numPlayers, skill, tableVal, victor;
    int *tableArr, *skillArr;
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
    victor = simulate(root, skillArr);
    printf("The Tournament winner is Skill of  %i.\n", victor);
    printf("\nPost Order:\n");
    postOrder(root);
    printf("\n");
    return 0;*/
}