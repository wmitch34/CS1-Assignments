#include <stdio.h>
#include <stdlib.h>
#define BLACK 1
#define RED 0

int main(){
	int rowCount, colCount, numGroupsRows, numGroupsCols;
	int ** grid, **rowData, **colData;

	scanf("%i", &rowCount);
	scanf("%i", &colCount);

	grid = (int **) calloc(rowCount, sizeof(int*));
	for (int i = 0; i < rowCount; i++){
		grid[i] = (int*) calloc(colCount, sizeof(int));
		for(int j = 0; j < colCount; j++){
			grid[i][j] = 0;
		}
	}

	//create arr for x num rows
	rowData = (int**)calloc(rowCount, sizeof(int*));
	for(int i = 0; i < rowCount; i++){
		//get number of groups for row i
		scanf("%i", &numGroupsRows);
		rowData[i] = (int *)calloc((numGroupsRows + 1), sizeof(int));
		rowData[i][0] = numGroupsRows; 
		for(int j = 1; j < numGroupsRows + 1; j++){
			//store groupings
			scanf("%i",&rowData[i][j]);
		}
	}

	//create arr for y num cols
	colData = (int**)calloc(colCount, sizeof(int*)); 
	for(int i = 0; i < colCount; i++){
		//get number of groups for col i
		scanf("%i", &numGroupsCols);
		colData[i] = (int*)calloc((numGroupsCols + 1), sizeof(int));
		colData[i][0]= numGroupsCols;
		for(int j = 1; j < numGroupsCols + 1; j++){
			//store number of groups in col
			scanf("%i",&colData[i][j]);
		}
	}

	//print grid
	for(int i = 0; i < rowCount; i++){
		for(int j = 0; j< colCount; j++){
			printf("%i ", grid[i][j]);
		}
		printf("\n");
	}

	//print for row data
	for(int i = 0; i < rowCount; i++){
		printf("Row %i: ", i);
		for(int j = 1; j < rowData[i][0] + 1; j++){
			printf("%i ", rowData[i][j]);
		}
		printf("\n");
	}

	//print for col data
	for(int i = 0; i < colCount; i++){
		printf("Col %i: ", i);
		for(int j = 1; j< colData[i][0] + 1; j++){
			printf("%i ", colData[i][j]);
		}
		printf("\n");
	}

	return 0;
}