#!/usr/bin/python3
"""[This function tests out how many operations it takes to reach n]
"""


def minOperations(n):
    """[Calculates minumum amount of operations]

    Args:
        n ([int]): [number of operations]
    """
    number = 1
    tmp = 0
    ops = 0
    if type(n) is not int or n < 2:
        return 0
    else:
        for itr in range(n):
            if number == n:
                return ops

            elif n % number == 0:
                tmp = number
                number += tmp
                ops += 2

            else:
                number += tmp
                ops += 1
