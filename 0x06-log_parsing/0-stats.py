#!/usr/bin/python3
"""[A script that reads stdin line by line and computes metrics:]
"""

from os import pardir
import sys
import fileinput

counter = 0
filesize = 0
status = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

try:
    for line in fileinput.input():
        counter += 1
        parsedLine = line.split()

        code = parsedLine[len(parsedLine) - 2]
        size = parsedLine[len(parsedLine) - 1]

        if code in status.keys():
            status[code] += 1

        if size.isdigit():
            filesize += int(size)

        if counter % 10 == 0:
            print("File size: {}".format(filesize))

            for item in sorted(status.items()):
                if item[1] != 0:
                    print("{}: {}".format(item[0], item[1]))

    print("File size: {}".format(filesize))
    for item in sorted(status.items()):
        if item[1] != 0:
            print("{}: {}".format(item[0], item[1]))

except KeyboardInterrupt:
    print("File size: {}".format(filesize))
    for item in sorted(status.items()):
        if item[1] != 0:
            print("{}: {}".format(item[0], item[1]))
