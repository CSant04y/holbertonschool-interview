#!/usr/bin/python3
"""This module rotates a 2-D matrix clockwise"""


def rotate_2d_matrix(matrix):
    """[This function takes a Matrix and roatates it clockwise]

    Args:
        matrix ([type]): [description]
    """
    N = len(matrix)
    '''This loops through matrix columns'''
    for x in range(0, int(N / 2)):
        for y in range(x, N-x-1):
            '''This stores the current cell in temp var'''
            temp = matrix[x][y]
            matrix[x][y] = matrix[N-1-y][x]
            matrix[N-1-y][x] = matrix[N-1-x][N-1-y]
            matrix[N-1-x][N-1-y] = matrix[y][N-x-1]
            matrix[y][N-x-1] = temp
