#ifndef _SANDPILES_H_
#define _SANDPILES_H_

/**** libraries ****/

#include <stdio.h>
#include <stdlib.h>


/**** Prototypes ****/

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void topple_grid(int grid1[3][3], int grid3[3][3]);
void add_around(int grid1[3][3], int row, int col);
void grid_check(int grid1[3][3], int grid3[3][3]);
void print_grid1(int grid1[3][3]);
#endif
