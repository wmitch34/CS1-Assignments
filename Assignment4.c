#include <stdio.h>
#include <stdlib.h>
#define BUFFER 20

typedef struct customer{
    int bills;
    int tokens;
    int units;
    char name[BUFFER+1];
}customer;

long long int convertToUnits(int tokens, int bills, int tokenValue, int billValue){
    long int units;
    units = (tokens * billValue) + (bills * tokenValue);
    return units;
}
void merge(struct customer * customerList, int len){ 
    if (len <= 1) {
        return;
    }    
    int mid = len / 2;    
    merge(customerList, mid);    
    merge(customerList + mid, len-mid);
    
    struct customer * temp = (customer*)calloc(len, sizeof(customer));
    int fptr = 0;
    int bptr = mid;
    for (int i = 0; i < len; i++) {
        if (fptr < mid && bptr < len) {
            if (customerList[fptr].units > customerList[bptr].units){// if front is greater than back
                temp[i] = customerList[fptr];
                fptr++;
            } else { // back has larger (or equal) element
                temp[i] = customerList[bptr];
                bptr++;
            }        
        } else if (fptr < mid) { // front is non-empty, back is not
            temp[i] = customerList[fptr];
            fptr++;
        } else { // back is non-empty, front is not
            temp[i] = customerList[bptr];
            bptr++;
        }
    }    
    for (int i = 0; i < len; i++)
        customerList[i] = temp[i];    

    free(temp);
}

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

    merge(customerList, count);

    for(int i = 0; i < count; i++){
        printf("%s ", customerList[i].name);
        //printf("%d ", customerList[i].tokens);
        //printf("%d ", customerList[i].bills);
        printf("%d \n", customerList[i].units);
    }

    free(customerList);

    return 0;
}

