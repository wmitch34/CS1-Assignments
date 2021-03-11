#include <stdio.h>
#include <stdlib.h>
#define BUFFER 20

typedef struct gamer{
	int tokens;
	char name[BUFFER + 1];
	struct gamer * pointer;
}gamer;

gamer * addGamer(){
	gamer * newGamer;
	newGamer = calloc(1, sizeof(gamer));
	return newGamer;
}

gamer * removeGamer(){

}

int main(){
	struct gamer * head = NULL;
	int userInput;
	do{
		scanf("%d", &userInput);
		switch(userInput){
			case 0:
			break;

			case 1:
			//input gamer
			//add gamer
			break;

			case 2:
			//removeGamer
			break;

		}
	}while(userInput != 0);
	
	return 0;
}