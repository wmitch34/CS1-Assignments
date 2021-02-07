#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Will Mitchell feb 5, 2021
//pick a number between 1 and n
//enter n in terminal
//program will guess numbers
//you reply warmer "w" colder "c"
//of yes "y"

void generateGuess(int, int*, int*);
int askTheCat();
int mid(int, int);

int main(){
	int guess, answer, previousGuess;
	int high, max, i = 0, low = 1, maxGuess;

	scanf("%d", &high);

	max = high;
	maxGuess = (1 + (2 * (ceil((log10(max))/(log10(2))))));

	printf("maximum number of guesses: %d\n", maxGuess);
	printf("%d\n",mid(low, high));
	i++;
	answer = askTheCat();
	printf("%d\n", 1 + mid(low, high));
	i++;
	answer = askTheCat();
	if (answer == 1){
		return 0;
	}
	
	while (i < maxGuess){	
		if (answer == 1){
			return 0;
		}
		if(answer == 3){
			low = (mid(low, high));
			high = high;
			guess = mid(low, high);
			printf("%d\n", guess);
			i++;
			answer = askTheCat();
			if (answer != 1 && i < maxGuess){
				guess = guess + 1;
				printf("%d\n", guess);
				i++;
				answer = askTheCat();
			}
		}
		if(answer == 4){
			low = low;
			high = mid(low, high);
			guess = mid(low, high);
			printf("%d\n", guess);
			i++;
			answer = askTheCat();
			if (answer != 1 && i < maxGuess){
				guess = guess + 1;
				printf("%d\n", guess);
				i++;
				answer = askTheCat();
			}
		}
		if(answer == 5){
			guess = mid(previousGuess, guess);
			printf("%d\n", guess);
			answer = askTheCat();
		}
		printf("number of guesses attempted: %d\n", i);
	}
	printf("Game Over!\n");
	return 0;
}

int mid(int low, int high){
	int mid = ((high - low)/2) + low;
	return mid;
}

int askTheCat(){
	char response[50];
	scanf(" %[^\n]s", response);
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
	if (strcmp(response, "No change") == 0){
		return 5;
	}
	else return 6;
}