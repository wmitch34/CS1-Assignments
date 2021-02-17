#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 21

void destroyArray(char ** arrList, int count);
int permutations(char** arrList, char** retList, int retCount, int len);

int main(){
	int count;
	char ** arrList;
	char ** retList;

	scanf("%d", &count);
	int len = count - 1;
	arrList = (char**) calloc(count, sizeof(char *));
	retList = (char**) calloc(count, sizeof(char *));

	for(int i = 0; i < count; i++){
		arrList[i] = (char*) malloc(BUFFER+1);
		retList[i] = (char*) malloc(BUFFER+1);
		scanf("%s", arrList[i]);
	}
    //if (permutations(arrList, retList, 0, len) == 1){
        for(int i = 0; i < count; i++){
            printf("%s", retList[i]);
        }
    //}
	destroyArray(arrList, count);
	destroyArray(retList, count);
	return 0;
}

int permutations(char** arrList, char** retList, int retCount, int len){
    if (retList[retCount][strlen(retList[retCount])-1] == arrList[len][0]){
        retList[retCount + 1] = arrList[len];
        permutations(arrList, retList, retCount + 1, len - 1);
    }
    else permutations(arrList, retList, retCount, len - 1);
}

void destroyArray(char ** arrList, int count){
    for(int i = 0; i < count; i++){
        free(arrList[i]);
    }
    free(arrList);
}
