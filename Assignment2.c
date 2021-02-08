#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Will Mitchell feb 8, 2021
//Prototyping for only 2 functions
int askTheCat();
int mid(int, int);

int main(){
	int guess, answer, previousGuess;
	int high, low = 1;
	//get upper bound
	scanf("%d", &high);
	//guess mid
	printf("%d\n",mid(low, high));
	fflush(stdout);
	//ask the cat if guess is right/
	//wrong/warmer/colder
	answer = askTheCat();
	//if 1 ("Yes!!!") were done
	if (answer == 1){
			return 0;
	}
	//if not 1 ("Yes!!!"),
	//Guess mid+1 to establish
	//new upper and lower bound
	printf("%d\n", 1 + mid(low, high));
	fflush(stdout);
	answer = askTheCat();
	//run print/scan loop for as long as 
	//askTheCat doesnt return 1 ("Yes!!!")
	while (answer != 1){	
		if(answer == 3){
			//establish new upper/lower based
			//on answer and guess new mid
			low = (mid(low, high));
			high = high;
			previousGuess = guess;
			guess = mid(low, high);
			printf("%d\n", guess);
			fflush(stdout);
			answer = askTheCat();
			if (answer != 1){
				//Guess mid+1 to establish
				//new upper and lower bound
				previousGuess = guess;
				guess = guess + 1;
				printf("%d\n", guess);
				fflush(stdout);
				answer = askTheCat();
			}
		}
		else if(answer == 4){
			//establish new upper/lower based
			//on answer and guess new mid
			low = low;
			high = mid(low, high);
			previousGuess = guess;
			guess = mid(low, high);
			printf("%d\n", guess);
			fflush(stdout);
			answer = askTheCat();
			if (answer != 1){
				//Guess mid+1 to establish
				//new upper and lower bound
				previousGuess = guess;
				guess = guess + 1;
				printf("%d\n", guess);
				fflush(stdout);
				answer = askTheCat();
			}
		}
		else if(answer == 5){
			//This case should never be initiated, but
			//if previousGuess == guess, print the 
			//value in the middle of them.
			//this value should always be the target
			guess = mid(previousGuess, guess);
			printf("%d\n", guess);
			fflush(stdout);
			answer = askTheCat();
		}
		else{
			//whenever the answer is somthing unexpected,
			//error message is printed, upper and lower bound
			//stay the same, and askThe cat is called again
			printf("Invalid Input. Try again: \n");
			fflush(stdout);
			answer = askTheCat();
		}
	}
	//if at any point in the loop answer == 1 
	//("Yes!!!"), then program is done
	return 0;
}
//function returns the mid point point
//btwn 2 values, cutting off decimals.
int mid(int low, int high){
	int mid = ((high + low)/2);
	return mid;
}
//function scans cats answer and returns an
//corresponding int. Main loop uses the returned 
//int to alter upper and lower bound
int askTheCat(){
	char response[50];
	scanf(" %[^\n]s", response);
	
	if (strcmp(response, "No.") == 0){
		return 2;
	}
	else if (strcmp(response, "No. Warmer.") == 0){
		return 3;
	}
	else if (strcmp(response, "No. Colder.") == 0){
		return 4;
	}
	else if (strcmp(response, "Yes!!!") == 0){
		return 1;
	}
	else if (strcmp(response, "No. No change.") == 0){
		return 5;
	}
	else if (strcmp(response, "Game Over") == 0){
		return 6;
	}
	else return 7;
}