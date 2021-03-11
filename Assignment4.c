#include <stdio.h>
#include <stdlib.h>
#define BUFFER 20
//Will Mitchell Mar 1, 2021
//program adds customer name and payment info to array
//then sorts and prints customer names by amount paid from greatest to least.
//The merge sort is heavily inspired by Dr. Meades version, but
//adapted to run my data structure.
typedef struct customer{
    int bills;
    int tokens;
    long long int units;
    char name[BUFFER+1];
}customer;
//Converts customer's number of bills/tokens into a standardized unit
//based on user input value ratio of tokens to bills
long long int convertToUnits(int tokens, int bills, int tokenValue, int billValue){
    long long int units;
    units = (tokens * billValue) + (bills * tokenValue);
    return units;
}
//merge sort that sorts struct customer arr from greatest to least
//based on the  int value in the units element
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
        //if either arr array is invalid populate temp with value from valid array
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
    //get number of customers
    scanf("%d", &count);
    //initialize customer ptr arr based on user input
    customerList = (customer*) calloc(count, sizeof(customer));
    //populate customer structs one at a time excluding the units element
    for(int i = 0; i < count; i++){
        scanf("%s", customerList[i].name);
        scanf("%d", &customerList[i].tokens);
        scanf("%d", &customerList[i].bills);
    }
    //scan user input token/bill ration
    scanf("%d", &tokenValue);
    scanf("%d", &billValue);
    //can populate units element using the function
    for(int i = 0; i < count; i++){
        customerList[i].units = convertToUnits(customerList[i].tokens, customerList[i].bills, tokenValue, billValue);
    }
    //call merge sort using the number of customers as initial length
    merge(customerList, count);
    //print cust names of the now sorted arr
    for(int i = 0; i < count; i++){
        printf("%s\n", customerList[i].name);
    }

    free(customerList);

    return 0;
}
