#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 21

void permute(int max, int index, char ** array);
void destroyArray(char ** arrList, int max);
int check(char ** array, int max);

int main(){
    int max;
	char ** arrList;

	scanf("%d", &max);
	arrList = (char**) calloc(max, sizeof(char *));

	for(int i = 0; i < max; i++){
		arrList[i] = (char*) malloc(BUFFER+1);
		scanf("%s", arrList[i]);
	}
    permute(max, 0, arrList);
    destroyArray(arrList, max);
    return 0;
}

void permute(int max, int index, char ** array){
    if (index == max){
        if(check(array, max) == 1){
            for(int i = 0; i < max; i ++){
                printf("%s ", array[i]);
            }
            printf("\n");
            return;
        }
    }
    else{
        for (int i = index; i < max; i++){
            char tmpVar[BUFFER];
            strcpy(tmpVar, array[index]);
            strcpy(array[index], array[i]);
            strcpy(array[i], tmpVar);

            permute(max, index + 1, array);

            strcpy(tmpVar, array[index]);
            strcpy(array[index], array[i]);
            strcpy(array[i], tmpVar);
        }
        return;
    }
}

int check(char ** array, int max){
    for(int i = 0; i < max - 1; i++){
        if (array[i][strlen(array[i])-1] != array[i + 1][0]){
            return 0;
        }
    }
    return 1;

}

void destroyArray(char ** arrList, int max){
    for(int i = 0; i < max; i++){
        free(arrList[i]);
    }
    free(arrList);
}