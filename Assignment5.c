#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LEN 20

//create structure for nodes
typedef struct gamer{
	int tokens;
	char name[BUFFER_LEN + 1];
	struct gamer * next;
}gamer;

//push function adds gamer to stack. pass curr head and newGamer
gamer * push(gamer * head, gamer * newGamer){
    //if the stack was empty, our new head is the recently created and passed gamer
	if(head == NULL){
		return newGamer;
	}
	//if the added gamer has MORE OR THE SAME number of tokens as the current head,
	//the new gamer is added to the stack with its values as the new head
	else if (newGamer->tokens >= head->tokens){
		newGamer->next = head;
	}
	//else the added gamer has LESS tokens then the current head.
	//we don't need to record their information, but we do need to add a node
	//to the stack. The data from curr head is copied to newhead and added
	//to the stack as new head
	else{
		newGamer->tokens = head->tokens;
		strcpy(newGamer->name, head->name);
		newGamer->next = head;
	}
	return newGamer;
//this function works due to the stipulations of the prompt. We only ever need to print the
//name of the gamer who currently has the most tokens. The size of the stack is important,
//but the names of the people in it are not. Therefore, we always add a node when someone enters,
//but we only record the name if they are the new MVP. this way, the size of the stack is accurate,
//and the MVP's name is always available at the top.
}

//pop function used when a gamer is leaving
gamer * pop(gamer * head){
    //if head is NULL, we have no node to remove
	if (head == NULL){
		return NULL;
	}
	else{
		gamer * newHead;
        //newHead is node that current head points too
		newHead = head->next;
		//destroy the current head
		free(head);
		//return the new head.
		return newHead;
	}
}

void peek(gamer * head){
    //if stack is empty return without printing
	if (head == NULL){
		return;
	}
	//else print head of stack-- see push function comments
	//for details on tracking current mvp
	else{
		printf("%s\n", head->name);
	}
}

//recursive function to free nodes from the top
//of the stack down to the bottom
void destroyStack(gamer * head){
    //base case: if current node ptr is NULL
	if(head == NULL){
		return;
	}
	else{
        //recursive call: send current.next and check
        //to see if it points to NULL
		destroyStack(head->next);
		free(head);
	}
}

gamer * createNode(int tokens, char * name){
	struct gamer * newGamer;
	//allocate 1 new node
	newGamer = (gamer*) malloc(sizeof(gamer));
	newGamer->tokens = tokens;
	strcpy(newGamer->name, name);
	//newGamer pointer is set to NULL
	//head will point to newGamer node later
	newGamer->next = NULL;
	return newGamer;
}

int main(){
	struct gamer * head = NULL;
	struct gamer * newGamer;
	//while loop entrance depends on value of userInput, so I initialize as good practice
	int userInput = -1, tokens;
	char name[BUFFER_LEN + 1];
    //switch menu in while loop for user getting input
    //'0' is exit and default case is included for invalid input
	while(userInput != 0 ){
		scanf("%d", &userInput);
		switch(userInput){
			case 0:
			break;

			case 1:
			scanf("%d", &tokens);
			scanf("%s", name);
			newGamer = createNode(tokens, name);
			head = push(head, newGamer);
			break;

			case 2:
			head = pop(head);
			break;

			case 3:
            //head is always MVP
			peek(head);
			break;

			default:
            		break;
		}
	}
	//NO LEAKS ALLOWED!!!
	destroyStack(head);
	return 0;
}
