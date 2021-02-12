#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursiveFact(int);

int main(){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("%d! is equal to %d\n", n, recursiveFact(n));
	return 0;
}

int recursiveFact(int n){
	if(n ==1){
		return 1;
	}
	else{
		return n * recursiveFact(n-1);
	}
}