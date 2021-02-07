#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Will Mitchell feb 5, 2021
//pick a number between 1 and n
//enter n in terminal
//program will guess numbers
//you reply warmer "w" colder "c"
//of yes "y"
int askTheCat();
int mid(int, int);

int main(){
	int guess, answer, previousGuess;
	int high, i = 0, low = 1;

	scanf("%d", &high);
	printf("%d\n",mid(low, high));

	answer = askTheCat();
	if (answer == 1){
			return 0;
		}
	printf("%d\n", 1 + mid(low, high));
	answer = askTheCat();
	
	while (answer != 1){	
		if(answer == 3){
			low = (mid(low, high));
			high = high;
			previousGuess = guess;
			guess = mid(low, high);
			printf("%d\n", guess);
			answer = askTheCat();
			if (answer != 1){
				previousGuess = guess;
				guess = guess + 1;
				printf("%d\n", guess);
				answer = askTheCat();
			}
		}
		else if(answer == 4){
			low = low;
			high = mid(low, high);
			previousGuess = guess;
			guess = mid(low, high);
			printf("%d\n", guess);
			answer = askTheCat();
			if (answer != 1){
				previousGuess = guess;
				guess = guess + 1;
				printf("%d\n", guess);
				answer = askTheCat();
			}
		}
		else if(answer == 5){
			guess = mid(previousGuess, guess);
			printf("%d\n", guess);
			answer = askTheCat();
		}
		else{
			printf("Invalid Input");
		}
	}
	return 0;
}

int mid(int low, int high){
	int mid = ((high + low)/2);
	return mid;
}

int askTheCat(){
	char response[50];
	scanf(" %[^\n]s", response);
	
	if (strcmp(response, "n") == 0){
		return 2;
	}
	else if (strcmp(response, "w") == 0){
		return 3;
	}
	else if (strcmp(response, "c") == 0){
		return 4;
	}
	else if (strcmp(response, "y") == 0){
		return 1;
	}
	else if (strcmp(response, "No change") == 0){
		return 5;
	}
	else if (strcmp(response, "Game Over") == 0){
		return 6;
	}
	else return 7;
}