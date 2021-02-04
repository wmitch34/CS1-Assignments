#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//learning how to use git hub tbh
int checkResponse(char* response);
int generateGuess(int respNum);

int main(){
	//input
	char response[1000];
	int guess, max;
	int i, answer;
	//give a max number
	scanf("%d", &max);

	//initialize guess
	guess = (max/2);

	for (i = 0; i < (max/2); i++){
		printf("%d\n", guess);
		scanf(" %[^\n]s", response);
		answer = checkResponse(response);
		if (answer == 1){
			return 0;
		}
		if (answer == 2){
			guess = (max/4);
		}
		if (answer == 3){
			guess = guess+1;
		}
		if (answer == 4){
			guess = guess-1;
		}
		if (answer == 5){
			printf("Invalid Entry\n");
		}



	}


	return 0;
}

int checkResponse(char * response){
	if (strcmp(response, "y") == 0){
		return 1;
	}
	if (strcmp(response, "n") == 0){
		return 2;
	}
	if (strcmp(response, "w") == 0){
		return 3;
	}
	if (strcmp(response, "c") == 0){
		return 4;
	}
	else return 5;
}

