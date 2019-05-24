//#include<stdio.h>
//#include<conio.h>
//
//void main() {
//	int num;
//	char term;
//	int a = scanf_s("%d%c", &num, &term);
//	if (a != 2 || term != '\n')
//		printf("failure\n");
//	else
//		printf("valid integer followed by enter key\n");
//	_getch();
//}

#include "stdio.h"
#include <conio.h>




void printArray(char *matrix[], int n)
{
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j<n; j++) {
			printf("%c", matrix[i][j]);
		}
	}
}
//
//void spiral(char matrix[][3], int n, char adrr[]) {
//	int column = n / 2;
//	int row = n / 2;
//	int i = 0;
//	while (column != n + 1 && row != 0 || column != 0 && row != n + 1) {
//		while (matrix[column - 1][row] == NULL) {
//			matrix[column - 1][row] = adrr[i];
//		}
//		i++;
//		while (matrix[column][row - 1] == NULL) {
//			matrix[column][row - 1] = adrr[i];
//		}
//		i++;
//		while (matrix[column + 1][row] == NULL) {
//			matrix[column + 1][row] = adrr[i];
//		}
//		i++;
//		while (matrix[column][row + 1] == NULL) {
//			matrix[column][row + 1] = adrr[i];
//		}
//		i++;
//	}
//}

void main() {
	int n = 3;
	char adrr[] = { 'H','I','L','L','O','W','A','D' };
	int matrix[3][3];

	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j<n; j++) {
			matrix[i][j]=-1;
		}
	}
	
	int column = n / 2;
	int row = n / 2;
	int i = 0;
	matrix[column][row] = adrr[i];
	i++;
	while (column != n + 1 && row != 0 || column != 0 && row != n + 1) {
		while (matrix[column ][row--] == -1) {
			matrix[column ][row-1] = adrr[i];
		}
		i++;
		while (matrix[column--][row ] == -1) {
			matrix[column-1][row ] = adrr[i];
		}
		i++;
		while (matrix[column][row++] == -1) {
			matrix[column][row+1] = adrr[i];
		}
		i++;
		while (matrix[column++][row] == -1) {
			matrix[column+1][row] = adrr[i];
		}
		i++;

	}

	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j<n; j++) {
			printf("%c", matrix[i][j]);
		}
	}
	_getch();
}