#!/usr/bin/python3
"""[This method determins if lockboxes can be opened]
"""


def canUnlockAll(boxes):
    """[Checks lists of lists to see if it contains key to other boxes]
    """
    keys = {
        0:True
    }
    counter = 0
    try:

        for i in range(1, len(boxes)):
            keys[i] = False

        while counter < len(boxes) and False in keys.values():
            for i in keys:
                if keys[i] is True:
                    for j in boxes[i]:
                        if j > 0 and j < len(boxes):
                            keys[j] = True
                    counter += 1
        if False in keys.values():
            return False
        return True
    except:
        return False