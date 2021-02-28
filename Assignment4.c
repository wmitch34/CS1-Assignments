#include <stdio.h>
#include <stdlib.h>
#define BUFFER 20

typedef struct customer{
    int bills;
    int tokens;
    int units;
    char name[BUFFER+1];
}customer;

long long int convertToUnits(int tokens, int bills, int tokenValue, int billValue);
void mergeArrays(int * customerList, int leftBound, int rightBound, int mid);
void mergeSort(int * CustomerList, int leftBound, int rightBount);

int main(){
    customer * customerList;
    int bills, tokens, count, tokenValue, billValue;
    char name[BUFFER+1];

    scanf("%d", &count);
    customerList = (customer*) calloc(count, sizeof(customer));

    for(int i = 0; i < count; i++){
        scanf("%s", customerList[i].name);
        scanf("%d", &customerList[i].tokens);
        scanf("%d", &customerList[i].bills);
    }

    scanf("%d", &tokenValue);
    scanf("%d", &billValue);

    for(int i = 0; i < count; i++){
        customerList[i].units = convertToUnits(customerList[i].tokens, customerList[i].bills, tokenValue, billValue);
    }

    //callmerge sort function to sort customers in customer array from highest to lowest

    for(int i = 0; i < count; i++){
        printf("%s ", customerList[i].name);
        printf("%d ", customerList[i].tokens);
        printf("%d ", customerList[i].bills);
        printf("%d \n", customerList[i].units);
    }

    free(customerList);

    return 0;
}

long long int convertToUnits(int tokens, int bills, int tokenValue, int billValue){
    long int units;
    units = (tokens * billValue) + (bills * tokenValue);
    return units;
}
void mergeArrays(int * customerList, int leftBound, int rightBound, int mid){

}
void mergeSort(int * CustomerList, int leftBound, int rightBount){

}
