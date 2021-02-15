#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 100000
//some prototypes
void generateHandle(char *);
void destroyArray(char**, int);

int main(){
    char ** nameList;
    int count;
    //get how many names to process
    scanf("%i", &count);
    //allocate memory for name list
    nameList = (char**)calloc(count, sizeof(char*));
    //for loop for reading in names
    for(int i = 0; i < count; i++){
        //allocate for each name individually
        nameList[i] = (char *) malloc(BUFFER);
        //read individual name in
        scanf(" %[^\n]s", nameList[i]);
    }
    //for each individaul name, generate handle
    //handle print is in the function
    for (int i = 0; i < count; i ++){
        generateHandle(nameList[i]);
    }
    //detroy all dynamically allocated 
    //memory in this function
    destroyArray(nameList, count);
    return 0;
}

void generateHandle(char * name){
    char * word;
    //chop off each word and process
    //them individually
    word = strtok(name, " ");
    //continue chopping untill the end of the string
    while(word != NULL){
        //if case for single letter name case
        if(strlen(word) == 1){
            //print single character
            printf("%c", word[0]);
            word = strtok(NULL, " ");
        }
        //else case for other multicharacter words
        else{
            //print first letter and last letter
            printf("%c%c",word[0], word[strlen(word)-1]);
            word = strtok(NULL, " ");
        }
    }
    //newline to sperate generated handle
    printf("\n");
}

void destroyArray(char ** nameList, int count){
    //free each individual element of the array
    for(int i = 0; i < count; i++){
        free(nameList[i]);
    }
    //free the whole array
    free(nameList);
}