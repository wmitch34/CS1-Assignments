#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void generateGuess(int, int, int);
int askTheCat(int);

int main(){
	char response[50];
	int max, guess, responseInt;
	//scan for max
	scanf("%d", &max);
	printf("%d\n", max/2);
	responseInt = askTheCat(max/2);
	generateGuess(1, max, responseInt);
	return 0;
}

void generateGuess(int low, int high, int response){
	int answer;
	int guess;

	if(response == 1){
		return;
	}
	if(response == 2){
		guess = ((high/2)+1);
		printf("%d\n", guess);
		answer = askTheCat(guess);
		generateGuess(low, high, answer);

	}
	if(response == 3){
		low = (((high-low)/2)+low);
		high = high;
		guess = (((high-low)/2)+low);
		printf("%d\n", guess);
		answer = askTheCat(guess);
		generateGuess(low, high, answer);

	}
	if(response == 4){
		low = low;
		high = (((high-low)/2)+low);
		guess = (((high-low)/2)+low);
		printf("%d\n", guess);
		answer = askTheCat(guess);
		generateGuess(low, high, answer);
	}

	
}
//Takes in a computer generated guess
//returns a number based on user input string
// "Yes!!!" 	 = 1
// "No." 		 = 2
// "No. Warmer." = 3
// "No. Colder." = 4
// any invalid entry returns 5
int askTheCat(int guess){
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