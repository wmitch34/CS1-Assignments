#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node{
    int value;    
    Node *l, * r;
};

Node * createNode(int value){
    Node * ret = calloc(1, sizeof(Node));
    ret->value = value;
    ret->r = ret->l = NULL;
    printf("createNode success.\n");    
    return ret;
}

int sumOfLeaves(Node * root){
    if (root == NULL) return 0;
    if (root->r == NULL && root->l == NULL){
            return root->value;    
    }    
    int ans = 0;    
    ans += sumOfLeaves(root->r);    
    ans += sumOfLeaves(root->l);    
    return ans;
}

// Method to find the smallest node in the tree
Node * findSmallest(Node * root){    
	// if there is a smaller node (left child)    
	// then find the smallest in that left subtree    
	if (root->l != NULL)
	    return findSmallest(root->l);
	    // No smaller node (no left child)
    return root; // base case after recursive call woah
}

// remove2 a value from a tree and return the resulting root
Node * remove2(Node * root, int value){
    if (root == NULL){
    	return root;
    }        
    if (root->value == value){
        // 0 children        
        if (root->r == NULL && root->l == NULL){
            free(root);
            // empty tree
            return NULL;
        }
        // 1 child
        if (root->r == NULL || root->l == NULL){
            Node * child = root->r;
                if (child == NULL) child = root->l;
                free(root);
                return child;
        }
        // 2 children :(
        // Find the min in the larger sub (replacement)
        Node * smallest = findSmallest(root->r);
        printf("Smallest is %d\n", smallest->value);
        // swap values
        int tmp = root->value;
        root->value = smallest->value;
        smallest->value = tmp;
        // Remove the value from that right subtree
        root->r = remove2(root->r, value);
        // Root is still the same (ideally)
        return root;    
    }    
    if (root->value < value){
        root->r = remove2(root->r, value);
    }    
    if (root->value > value){
        root->l = remove2(root->l, value);   
    }    
    return root;
}

// Return the root of the tree
Node * insert(Node * root, int value){
    if (root == NULL){
        return createNode(value);
    }
    // Don't add duplicates (optional)
    if (root->value == value){
        return root;   
    }    
    // root is smaller than our target    
    if (root->value < value){
        root->r = insert(root->r, value);
    }
    else{
        root->l = insert(root->l, value);
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

    printf("%d ", root->value);    

    // beginning the process of moving up
}

int  contains(Node * root, int value){
    if (root == NULL){
        return 0;    
    }
    if (root->value == value){
        return 1;
    }
    // root is smaller than target
    if (root->value < value){
        // go right (has larger values)
            return contains(root->r, value);
    }
    else{
        // root is greater than target
        // go left (has smaller values)
        return contains(root->l, value);     
    }
}

int main(){
	int numPlayers, skill;
	int * skillArr;
	Node * root = NULL;
	printf("How many palyers?\n");
	scanf("%i", &numPlayers);
	printf("%i\n", numPlayers);

	skillArr = (int*)calloc(numPlayers, sizeof(int));
	printf("Enter The table activation order\n");
	for(int i = numPlayers - 2 ; i >= 0; i--){
		scanf("%i", &skill);
		skillArr[i] = skill;
	}

	printf("Post Order:\n");
	for(int i = 0; i < numPlayers - 1; i++){
		root = insert(root, skillArr[i]);
		printf("%i ", skillArr[i]);
	}
	postOrder(root);

	printf("\n");
	printf("\n");
	printf("%i", contains(root, 3));
	printf("\n");
	printf("\n");
	return 0;
}