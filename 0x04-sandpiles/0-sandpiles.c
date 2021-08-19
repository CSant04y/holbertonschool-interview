#include "sandpiles.h"

/**
 * sandpiles_sum - This computes the sum of two tables
 * @grid1: This is the first stable grid
 * @grid2: This is the second stable grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int grid3[3][3], row, col, bool = 0;

	/*Add both grids to get theri sum in a seperate grid*/

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			grid3[row][col] = grid1[row][col];
			grid1[row][col] = grid2[row][col] + grid3[row][col];
			if (grid1[row][col] >= 4)
				bool = 1;
		}
	}
	/* getting the grid after it has been added*/
	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			grid3[row][col] = grid1[row][col];
		}
	}

	if (bool == 1)
	{
		print_grid1(grid3);
		topple_grid(grid1, grid3);
	}

}
/**
 * topple_grid - This topples the unstable sandbox
 * @grid1: This is the first stable grid
 * @grid3: This is the second stable grid
 *
 */
void topple_grid(int grid1[3][3], int grid3[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (grid3[row][col] > 3)
				add_around(grid1, row, col);
		}
	}
	grid_check(grid1, grid3);
}
/**
 * add_around - function adds grain of sand to surrnounding
 * @grid1: This is the first stable grid
 * @row: row
 * @col: column
 */
void add_around(int grid1[3][3], int row, int col)
{
	if (row > 0)
		grid1[row - 1][col] += 1;
	if (row < 2)
		grid1[row + 1][col] += 1;
	if (col > 0)
		grid1[row][col - 1] += 1;
	if (col < 2)
		grid1[row][col + 1] += 1;
	grid1[row][col] -= 4;
}

/**
 * grid_check - check to make sure grid is stable
 * @grid1: This is the first stable grid
 * @grid3: This is the second stable grid
 *
 */
void grid_check(int grid1[3][3], int grid3[3][3])
{
	int row, col, bool = 0;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (grid1[row][col] >= 4)
				bool = 1;
		}
	}
	if (bool == 1)
	{
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
				grid3[row][col] = grid1[row][col];
		}
		print_grid1(grid1);
		topple_grid(grid1, grid3);
	}

}
/**
 * print_grid1 - prints out grid
 * @grid1: This is the first stable grid
 *
 */
void print_grid1(int grid1[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j < 2)
				printf("%d ", grid1[i][j]);
			else
				printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}
