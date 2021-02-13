#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 100000

void generateHandle(char *);
void destroyArray(char**, int);

int main(){
    char ** nameList;
    int count;

    scanf("%i", &count);
    nameList = (char**)calloc(count, sizeof(char*));

    for(int i = 0; i < count; i++){
        nameList[i] = (char *) malloc(BUFFER);
        scanf(" %[^\n]s", nameList[i]);
    }
    for (int i = 0; i < count; i ++){
        generateHandle(nameList[i]);
    }
    destroyArray(nameList, count);
    return 0;
}

void generateHandle(char * name){
    char * word;
    word = strtok(name, " ");
    while(word != NULL){
        if(strlen(word) == 1){
            printf("%c", word[0]);
            word = strtok(NULL, " ");
        }
        else{
            printf("%c%c",word[0], word[strlen(word)-1]);
            word = strtok(NULL, " ");
        }
    }
    printf("\n");
}

void destroyArray(char ** nameList, int count){
    for(int i = 0; i < count; i++){
        free(nameList[i]);
    }
    free(nameList);
}
