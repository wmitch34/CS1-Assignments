#include <stdio.h>
#include <stdlib.h>
#define BUFFER 20

typedef struct customer{
    int bills;
    int tokens;
    char name[BUFFER+1];
}customer;

int main(){
    customer * arrList;
    int bills, tokens, count;
    char name[BUFFER+1];

    scanf("%d", &count);
    arrList = (customer*) calloc(count, sizeof(customer));

    for(int i = 0; i < count; i++){
        scanf("%s", arrList[i].name);
        scanf("%d", &arrList[i].tokens);
        scanf("%d", &arrList[i].bills);
    }
    for(int i = 0; i < count; i++){
        printf("%s", arrList[i].name);
        printf("%d", arrList[i].tokens);
        printf("%d", arrList[i].bills);
    }


    free(arrList);

    return 0;
}
