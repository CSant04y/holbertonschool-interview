#!/usr/bin/python3
"""
This function finds the permiter of an Island
on a 2-demensional matrix
"""


def island_perimeter(grid):
    '''Takes in grid and returns the perimeter'''
    # Define vars to hold lens
    grid_len, grid_row_len = len(grid), len(grid[0])

    # Now make vars for land so that we can calculate math as
    # As well as the neighboring land a.k.a vecinos
    land, vecino = 0, 0

    # Loop through length of grid first to access individual rows
    for i in range(grid_len):
        # Loop though lenght of row
        for j in range(grid_row_len):
            # Check to see if current position is equal to 1
            if grid[i][j] == 1:
                # add one to land == 4 perimeter
                land += 1

                # check for neighbors

                if i < grid_len - 1 and grid[i + 1][j] == 1:
                    vecino += 1
                if j < grid_row_len - 1 and grid[i][j + 1] == 1:
                    vecino += 1
    # Return calculation of land * 4
    return land * 4 - 2 * vecino
