#include <stdio.h>
#include <stdlib.h>
#define BUFFER 20
//Will Mitchell Mar 1, 2021
//program adds customer name and payment info to array 
//then sorts and prints customers by amount paid from greatest to least
//the merge sort is heavily inspired by Dr. Meades version, but
//adapted to run my data structure
typedef struct customer{
    int bills;
    int tokens;
    int units;
    char name[BUFFER+1];
}customer;
//function converts customer's number of bills/tokens into a standardized unit
//based on user input vale ratio of tokens to bills
long long int convertToUnits(int tokens, int bills, int tokenValue, int billValue){
    long long int units;
    units = (tokens * billValue) + (bills * tokenValue);
    return units;
}
void merge(struct customer * customerList, int len){ 
    //base case for merge sort: when array is 1 unit long
    if (len <= 1) {
        return;
    }    
    int mid = len / 2;
    //recursive call x2. Array is split int two sub arrays
    //and both are passed recursively until arr size is one    
    merge(customerList, mid);    
    merge(customerList + mid, len-mid);
    //alloc temp array for storing sorted customers
    struct customer * temp = (customer*)calloc(len, sizeof(customer));
    int fptr = 0;
    int bptr = mid;
    for (int i = 0; i < len; i++) {
        //if front array and back array are valid
        if (fptr < mid && bptr < len) {
            //pick smaller value
            if (customerList[fptr].units > customerList[bptr].units){
                temp[i] = customerList[fptr];
                fptr++;
            } else {
                temp[i] = customerList[bptr];
                bptr++;
            }
        //if either arr array is invalid choose value from valid array        
        } else if (fptr < mid) {
            temp[i] = customerList[fptr];
            fptr++;
        } else {
            temp[i] = customerList[bptr];
            bptr++;
        }
    }
    //copy sorted temp arr back into initial custustomer arr    
    for (int i = 0; i < len; i++){
        customerList[i] = temp[i];    
    }

    free(temp);
}

int main(){
    customer * customerList;
    int bills, tokens, count, tokenValue, billValue;
    char name[BUFFER+1];

    scanf("%d", &count);
    //initialize customer ptr arr based on user input
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

    merge(customerList, count);

    for(int i = 0; i < count; i++){
        printf("%s ", customerList[i].name);
        //printf("%d ", customerList[i].tokens);
        //printf("%d ", customerList[i].bills);
        //printf("%d \n", customerList[i].units);
    }

    free(customerList);

    return 0;
}

