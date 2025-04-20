/*
File: Matrix_Functions.c
Author: Sam Shedwick
Date: 4/19/2025

This file makes makes 3 matricies, A, B, and C. It then performs scalar 
multiplication on matrix B, performs matrix transposing to make matrix 
C transpose or C^T, performs matrix multiplication between matrix B and 
matrix C^T, and performs matrix addition between matrix A and matrix B. 
It prints out each matrix, printing matricies A, B, C, 3 * Matrix B, 
C^T,(3 * Matrix B) * C^T, and A + ((3 * Matrix B) * C^T).
*/

#include <stdio.h>

// Defines the variables for the row and column length of matrix A, 
// matrix B, matrix C, and matrix C transposed
#define A_ROW_LENGTH 2
#define A_COL_LENGTH 2
#define B_ROW_LENGTH 3
#define B_COL_LENGTH 2
#define C_ROW_LENGTH 3
#define C_COL_LENGTH 2
#define C_ROW_TRANS_LENGTH C_COL_LENGTH
#define C_COL_TRANS_LENGTH C_ROW_LENGTH

int main()
{
	// Makes matrix A, B, and C, and inserts the proper values for them
	int matrixA[A_ROW_LENGTH][A_COL_LENGTH] = { {6, 8}, {4, 3} };
	int matrixB[B_ROW_LENGTH][B_COL_LENGTH] = { {1, 4}, {2, 5}, {3, 6} };
	int matrixC[C_ROW_LENGTH][C_COL_LENGTH] = { {2, 1}, {4, 3}, {6, 5} };

	// Prints out the values of matrix A, matrix B, and matrix C, with 
	// the proper matrix formatting
	printf("Matrix A:\n");
	for (int i = 0; i < A_COL_LENGTH; i++)
	{
		printf("[ ");
		for (int j = 0; j < A_ROW_LENGTH; j++)
		{
			printf("%d", matrixA[j][i]);
			printf("\t");
		}
		printf("]\n");
	}
	printf("\n");
	printf("Matrix B:\n");
	for (int i = 0; i < B_COL_LENGTH; i++)
	{
		printf("[ ");
		for (int j = 0; j < B_ROW_LENGTH; j++)
		{
			printf("%d", matrixB[j][i]);
			printf("\t");
		}
		printf("]\n");
	}
	printf("\n");
	printf("Matrix C:\n");
	for (int i = 0; i < C_COL_LENGTH; i++)
	{
		printf("[ ");
		for (int j = 0; j < C_ROW_LENGTH; j++)
		{
			printf("%d", matrixC[j][i]);
			printf("\t");
		}
		printf("]\n");
	}
	printf("\n");

	// Multiplies each value in matrix B by 3
	for (int i = 0; i < B_ROW_LENGTH; i++)
	{
		for (int j = 0; j < B_COL_LENGTH; j++)
		{
			matrixB[i][j] *= 3;
		}
	}

	// Prints out the values of the altered matrix B
	printf("3 * Matrix B:\n");
	for (int i = 0; i < B_COL_LENGTH; i++)
	{
		printf("[ ");
		for (int j = 0; j < B_ROW_LENGTH; j++)
		{
			printf("%d", matrixB[j][i]);
			printf("\t");
		}
		printf("]\n");
	}
	printf("\n");

	// Makes a new matrix C transpose. For each column in the new 
	// matrix, it sets the values of matrix C transpose to the value 
	// in the opposite index of matrix C
	int matrixCTranspose[C_ROW_TRANS_LENGTH][C_COL_TRANS_LENGTH];
	for (int i = 0; i < C_ROW_TRANS_LENGTH; i++)
	{
		for (int j = 0; j < C_COL_TRANS_LENGTH; j++)
		{
			matrixCTranspose[i][j] = matrixC[j][i];
		}
	}

	// Prints out the values of matrix C transpose
	printf("Matrix C^T:\n");
	for (int i = 0; i < C_COL_TRANS_LENGTH; i++)
	{
		printf("[ ");
		for (int j = 0; j < C_ROW_TRANS_LENGTH; j++)
		{
			printf("%d", matrixCTranspose[j][i]);
			printf("\t");
		}
		printf("]\n");
	}
	printf("\n");

	// Makes a new matrix B * C^T.
	int matrixBTimesCTranspose[C_ROW_TRANS_LENGTH][B_COL_LENGTH];

	// Tracker for the value obtained through the cross multiplication of matrix B and C^T
	int newValue = 0;

	// Goes through each column in matrix C^T
	for (int i = 0; i < C_ROW_TRANS_LENGTH; i++)
	{
		// Goes through each row of matrix B and cross multiplies 
		// the row of it by the current column of matrix C^T. It 
		// then sets the value in matrixBTimesCTranspose at i,j 
		// to the newValue tracker 
		for (int j = 0; j < B_COL_LENGTH; j++)
		{
			newValue = 0;
			for (int k = 0; k < B_ROW_LENGTH; k++)
			{
				newValue += matrixB[k][j] * matrixCTranspose[i][k];
			}

			matrixBTimesCTranspose[i][j] = newValue;
		}
	}

	// Prints out the values of matrix B * C^T
	printf("(3 * Matrix B) * C^T:\n");
	for (int i = 0; i < B_COL_LENGTH; i++)
	{
		printf("[ ");
		for (int j = 0; j < C_ROW_TRANS_LENGTH; j++)
		{
			printf("%d", matrixBTimesCTranspose[j][i]);
			printf("\t");
		}
		printf("]\n");
	}
	printf("\n");

	// For each index in matrix B * C^T, it adds the value of matrix A 
	// of that index to it
	for (int i = 0; i < C_ROW_TRANS_LENGTH; i++)
	{
		for (int j = 0; j < B_COL_LENGTH; j++)
		{
			matrixBTimesCTranspose[i][j] += matrixA[i][j];
		}
	}

	// Prints out the values of the altered matrix B * C^T
	printf("A + (3 * Matrix B) * C^T:\n");
	for (int i = 0; i < B_COL_LENGTH; i++)
	{
		printf("[ ");
		for (int j = 0; j < C_ROW_TRANS_LENGTH; j++)
		{
			printf("%d", matrixBTimesCTranspose[j][i]);
			printf("\t");
		}
		printf("]\n");
	}
	printf("\n");

	return 0;
}
