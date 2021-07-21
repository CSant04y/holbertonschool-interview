#!/usr/bin/python3
"""[This method determins if lockboxes can be opened]
"""


def canUnlockAll(boxes):
    """[Checks lists of lists to see if it contains key to other boxes]

    Args:
        boxes ([type]): [description]

    Returns:
        [type]: [description]
    """
    unlockedBoxes = [0]
    if boxes is None:
        return False
    newList = []
    size = len(boxes)

    if len(unlockedBoxes) == len(boxes):
        return True

    for item in boxes:
        if len(item) == len(boxes):
            return True
        if len(item) == 0 and item is not boxes[size - 1]:
            return False
        for i in item:
            newList.append(i)

    for index, keys in enumerate(boxes):
        if index in newList or index < size - 1:
            return True
        else:
            return False
