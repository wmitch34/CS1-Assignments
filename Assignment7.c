#include <stdio.h>
#include <stdlib.h>

int main(){
	int row, col, numGroupsRows, numGroupsCols;
	int ** grid;
	int * rowGroupArr, * colGroupArr;

	scanf("%i", &row);
	scanf("%i", &col);

	grid = (int **) calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++){
		grid[i] = (int*) calloc(col, sizeof(int));
	}

	for(int i = 0; i < row; i++){
		scanf("%i", &numGroupsRows);
		rowGroupArr = (int *)calloc(numGroupsRows, sizeof(int));
		for(int i = 0; i < numGroupsRows; i++){
			scanf("%i",&rowGroupArr[i]);
		}
	}

	for(int i = 0; i < col; i++){
		scanf("%i", &numGroupsCols);
		colGroupArr = (int*)calloc(numGroupsCols, sizeof(int));
		for(int i = 0; i < numGroupsCols; i++){
			scanf("%i",&colGroupArr[i]);
		}
	}

	return 0;
}