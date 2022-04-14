#!/usr/bin/python3
"""_This function returns a double array with values of pascals triangle_
"""

def pascal_triangle(n):
    newArray = [];
    if n <= 0:
        return []
    for i in range(n):
        newArray.append([])
        newArray[i].append(1)
        for j in range(1, i):
            newArray[i].append(newArray[i - 1][j - 1] + newArray[i - 1][j])
        if(i != 0):
            newArray[i].append(1)
    return newArray
