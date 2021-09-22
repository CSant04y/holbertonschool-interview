#!/usr/bin/python3
"""[This is a Method that determins if a dataset is Valid UTF-8]
"""


def validUTF8(data):
    """[Takes in a list of numbers and returns True if UTF-8 valid else False]

    Args:
        data ([list of ints]): [description]
    """

    '''Keeping track of preceding bytes'''
    n_bytes = 0

    for num in data:
        '''Format the given number into binary'''
        binaryNumber = format(num, "#010b")[-8:]

        '''Check to see if number of bytes'''
        if n_bytes == 0:

            for i in binaryNumber:
                if i == '0':
                    break
                n_bytes += 1

            if n_bytes == 0:
                continue

            if n_bytes == 1 or n_bytes > 4:
                n_bytes -= 1
                return False

        else:
            if not (binaryNumber[0] == 1 and binaryNumber[2] == 0):
                return False

        n_bytes -= 1

    return n_bytes == 0
