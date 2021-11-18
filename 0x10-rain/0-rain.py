#!/usr/bin/python3
'''This calculates the ammount of rain water'''


def rain(walls):
    """This calculates the rain"""

    n = len(walls)

    rain = 0
    for i in range(1, n - 1):

        # Find the maximum element on its left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Find the maximum element on its right
        right = walls[i]
        for j in range(i + 1, n):
            right = max(right, walls[j])

        # Update the maximum of rain collected
        rain += (min(left, right) - walls[i])

    return rain
