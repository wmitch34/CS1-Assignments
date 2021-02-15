#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 21

void destroyArray(char ** arrList, int count);
int permutation(char **);

int main(){
	int count;
	char ** arrList;
	char word;


	scanf("%d", &count);

	arrList = (char**) calloc(count, sizeof(char *));
	for(int i = 0; i < count; i++){
		arrList[i] = (char*) malloc(BUFFER * sizeof(char));
		scanf("%s", arrList[i]);
	}
	for(int i = 0; i < count; i++){
		printf("%s ", arrList[i]);
	}
	printf("\n");

	destroyArray(arrList, count);
	return 0;
}

int permutations(char** arrList){
	if(   ){
		return 1;
	}
	else{
		return ;
	}
}


void destroyArray(char ** arrList, int count){
    //free each individual element of the array
    for(int i = 0; i < count; i++){
        free(arrList[i]);
    }
    //free the whole array
    free(arrList);
}