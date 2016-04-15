/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int *spiral_rec(int, int, int **);
void spiral1(int**, int*, int, int, int, int, int);
int *spiral(int rows, int columns, int **input_array)
{
	int *res, index = 0;
	int r = 0, c = 0;
	if (rows <= 0 || columns <= 0)
	{
		res = NULL;
		return res;
	}
	if (input_array == NULL)
		return NULL;
	res = (int*)malloc((rows*columns)*sizeof(int));
	spiral1(input_array, res, index, rows, columns, r, c);
	return res;
}
void spiral1(int **input_array, int *res, int index, int rows, int columns, int r = 0, int c = 0)
{
	int i = 0;
	if (rows == 1 && columns == 1)
	{
		res[index++] = input_array[r][c];
	}
	for (i = c; i <= c + columns - 1; i++)
	{
		res[index++] = input_array[r][i];
	}
	for (i = r + 1; i <= r + rows - 1; i++)
	{
		res[index++] = input_array[i][c + columns - 1];
	}
	if (rows != 1)
		for (i = c + columns - 2; i > c; i--)
		{
			res[index++] = input_array[r + rows - 1][i];

		}
	if (columns != 1)
		for (i = r + rows - 1; i > r; i--)
		{
			res[index++] = input_array[i][c];

		}
	if (rows - 2 <= 0 || columns - 2 <= 0)
		return;
	else
		spiral1(input_array, res, index, rows - 2, columns - 2, r + 1, c + 1);
	return;
}