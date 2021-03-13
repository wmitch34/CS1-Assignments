#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LEN 20

typedef struct gamer{
	int tokens;
	char name[BUFFER_LEN + 1];
	struct gamer * next;
}gamer;

gamer * push(gamer * head, gamer * newGamer){
	if(head == NULL){
		return newGamer;
	}
	else if (newGamer->tokens >= head->tokens){
		newGamer->next = head;
	}
	else{
		newGamer->tokens = head->tokens;
		strcpy(newGamer->name, head->name);
		newGamer->next = head;
	}	
	return newGamer;
}

gamer * pop(gamer * head){
	if (head == NULL){
		return NULL;
	}
	else{
		gamer * newHead;
		newHead = head->next;
		free(head);
		return newHead;
	}
}

void peek(gamer * head){
	if (head == NULL){
		return;
	}
	else{
		printf("%s\n", head->name);
	}
	
}

void destroyStack(gamer * head){
	if(head == NULL){
		return;
	}
	else{
		destroyStack(head->next);
		free(head);
	}
}

gamer * createNode(int tokens, char * name){
	struct gamer * newGamer;
	newGamer = (gamer*) malloc(sizeof(gamer));
	newGamer->tokens = tokens;
	strcpy(newGamer->name, name);
	newGamer->next = NULL;
	return newGamer;
}

int main(){
	struct gamer * head = NULL;
	struct gamer * newGamer;
	int userInput = -1, tokens;
	char name[BUFFER_LEN + 1];

	while(userInput != 0 ){
		scanf("%d", &userInput);
		switch(userInput){
			case 0:
			break;

			case 1:
			//printf("Enter Number of tokens and name on one line\n");
			scanf("%d", &tokens);
			scanf("%s", name);
			newGamer = createNode(tokens, name);
			head = push(head, newGamer);
			break;

			case 2:
			head = pop(head);
			break;

			case 3:
			peek(head);
			break;

			default:
			break;

		}
	}

	destroyStack(head);
	
	return 0;
}