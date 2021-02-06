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
	int guess, answer;
	int low = 1;
	int high;
	

	scanf("%d", &high);
	printf("%d\n",mid(low, high));
	answer = askTheCat();
	printf("%d\n", 1 +mid(low, high));
	answer = askTheCat();

	while (answer != 1){
		if(answer == 3){
			low = (mid(low, high));
			high = high;
			printf ("range is %d - %d\n", low, high);
			guess = mid(low, high);
			printf("%d\n", guess);
			answer = askTheCat();
			if (answer != 1){
				guess = guess + 1;
				printf("%d\n", guess);
				answer = askTheCat();
			}
		}
		if(answer == 4){
			low = low;
			high = mid(low, high);
			printf ("range is %d - %d\n", low, high);
			guess = mid(low, high);
			printf("%d\n", guess);
			answer = askTheCat();
			if (answer != 1){
				guess = guess + 1;
				printf("%d\n", guess);
				answer = askTheCat();
			}
		}
	}
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
	else return 5;
}