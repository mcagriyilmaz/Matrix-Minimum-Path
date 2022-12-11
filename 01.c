#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10
void printMatrix(int matrix[SIZE][SIZE], int minimumPath[SIZE], int row, int column);
int main() {


	int  i, j, row = SIZE, column;
	int sumOfWeights;
	int min;
	
	printf("\n152120201087 Mehmet Cagri Yilmaz Introduction to Programming Lab Final Project\n\n");

	while (row != 0) {
		printf("\nEnter number of rows (0 to exit): ");
		scanf_s("%d", &row);
		while (row > SIZE) {
			printf("\nUse maximum 10x10 matrix dimension!\n ");
			printf("\nEnter number of rows (0 to exit): ");
			scanf_s("%d", &row);
		}

		if (row != 0) {
			printf("\nEnter number of columns: ");
			scanf_s("%d", &column);
			while (column > SIZE) {
				printf("\nUse maximum 10x10 matrix dimension!\n ");
				printf("\nEnter number of columns: ");
				scanf_s("%d", &column);
			}
			int matrix[SIZE][SIZE] = { 0 };
			int minimumPath[SIZE] = { 0 };
			int pathWeigths[SIZE][SIZE] = { 0 };

			srand(time(NULL));
			for (i = 0; i < row; i++) {
				for (j = 0; j < column; j++) {
					matrix[i][j] = (rand() % 10);
					pathWeigths[i][j] = matrix[i][j];
				}
			}


			for (i = 1; i < row; i++) {

				for (j = 0; j < column; j++) {
					if (j == 0) {
						min = pathWeigths[i - 1][0];

						if (pathWeigths[i - 1][j + 1] < min) {
							min = pathWeigths[i - 1][j + 1];
						}
					}
					else if (j == column - 1) { 
						min = pathWeigths[i - 1][j];

						if (pathWeigths[i - 1][j - 1] < min) {
							min = pathWeigths[i - 1][j - 1];
						}
					}
					else { 
						min = pathWeigths[i - 1][j - 1];
						for (int k = j - 1; k <= j + 1; k++) {
							if (pathWeigths[i - 1][k] < min) {
								min = pathWeigths[i - 1][k];
							}
						}
					}
					pathWeigths[i][j] = pathWeigths[i][j] + min;

				}
			}


			for (i = row - 1; i >= 0; i--) {
				if (i == row - 1) {
					sumOfWeights = pathWeigths[i][0];
					minimumPath[i] = 0;
					for (j = 1; j < column; j++) {
						if (pathWeigths[i][j] < sumOfWeights) {
							sumOfWeights = pathWeigths[i][j];
							minimumPath[i] = j;
						}
					}
				}
				else {
					if (minimumPath[i + 1] == 0) { 
						if (pathWeigths[i][1] < pathWeigths[i][0]) {
							minimumPath[i] = 1;
						}
						else {
							minimumPath[i] = 0;
						}
					}
					else if (minimumPath[i + 1] == column - 1) { 
						if (pathWeigths[i][column - 1] < pathWeigths[i][column - 2]) {
							minimumPath[i] = column - 1;
						}
						else {
							minimumPath[i] = column - 2;
						}
					}
					else { 
						min = pathWeigths[i][minimumPath[i + 1] - 1];
						minimumPath[i] = minimumPath[i + 1] - 1;
						for (int k = minimumPath[i + 1] - 1; k <= minimumPath[i + 1] + 1; k++) {
							if (pathWeigths[i][k] < min) {
								min = pathWeigths[i][k];
								minimumPath[i] = k;
							}
						}
					}
				}
			}

			printMatrix(matrix, minimumPath, row, column);

			printf("\nSum of weights:%d\n\n", sumOfWeights);

		}
	}
	return 0;
}
void printMatrix(int matrix[SIZE][SIZE],int minimumPath[SIZE],int row, int column) {
	printf("\n\n");
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			if (minimumPath[i] == j) {
				printf("\t[%d]", matrix[i][j]);
			}
			else {
				printf("\t%d", matrix[i][j]);

			}
		}
		printf("\n");
	}
}
