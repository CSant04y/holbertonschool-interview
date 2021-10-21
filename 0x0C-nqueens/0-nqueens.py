#!/usr/bin/python3
"""[This is the N-queens problem in which N ammount of queens
    are places on a chess board of n size]
"""

from sys import argv


def checkPosition(board, i, j, col):
    """[summary]

    Args:
        board ([list]): [This is the current postion of]
        i ([int]): [description]
        j ([int]): [description]
        col ([int]): [de]
    """

    if ((board[i] == j) or (board[i] == j - i + col) or
            (board[i] == i - col + j)):
        return True
    return False


def printTable(table, N):
    """[This prints the table]

    Args:
        table ([type]): [description]
        N ([type]): [description]
    """
    board = []

    for row in range(N):
        for col in range(N):
            if col == table[row]:
                board.append([col, row])
    print(board)


def findSolution(board, col, N):
    """[summary]

    Args:
        board ([List]): [List numbers in range of 0 to N ]
        col ([num]): [the currrent column]
    """
    if col == N:
        printTable(board, N)

    else:
        for j in range(N):
            mark = True
            for i in range(col):
                if checkPosition(board, i, j, col):
                    mark = False
            if mark:
                board[col] = j
                findSolution(board, col + 1, N)


def solveNQ():
    """[This function solves the N- Queen problem]

    Args:
        argv ([int]): [Int that indicated the size of N]
    """
    '''Checkes the lenght of arguments'''
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    '''Try and except to see if argv[1] is an integer'''
    try:
        N = int(argv[1])

    except BaseException:
        print("N must be a number")
        exit(1)

    '''This checks to make sure that the integer passed it grater then 4'''
    if N < 4:
        print("N must be at least 4")

    '''List comprehension to generate a list of lists'''
    board = [[0 for x in range(int(argv[1]))] for i in range(int(argv[1]))]

    col = 0
    '''This solution finds the safe postitons that n-queens are able to be
     placed'''
    findSolution(board, col, N)

solveNQ()
