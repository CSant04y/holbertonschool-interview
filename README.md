# 0x00. Lockboxes


## Requirements
### General
+ Allowed editors: <code data-beeline-skip="true">vi`, <code data-beeline-skip="true">vim`, <code data-beeline-skip="true">emacs`
+ All your files will be interpreted/compiled on Ubuntu 14.04 LTS using <code data-beeline-skip="true">python3` (version 3.4.3)
+ All your files should end with a new line
+ The first line of all your files should be exactly <code data-beeline-skip="true">#!/usr/bin/python3`
+ A <code data-beeline-skip="true">README.md` file, at the root of the folder of the project, is mandatory
+ Your code should be documented
+ Your code should use the <code data-beeline-skip="true">PEP 8` style (version 1.7.x)
+ All your files must be executable


## 0. Lockboxes
You have <code data-beeline-skip="true">n` number of locked boxes in front of you.
Each box is numbered sequentially from <code data-beeline-skip="true">0` to <code data-beeline-skip="true">n - 1` and each box may contain keys to the other boxes.

You have <code data-beeline-skip="true">n` number of locked boxes in front of you.
Each box is numbered sequentially from <code data-beeline-skip="true">0` to <code data-beeline-skip="true">n - 1` and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.
+ Prototype: <code data-beeline-skip="true">def canUnlockAll(boxes)`
+ <code data-beeline-skip="true">boxes` is a list of lists
+ A key with the same number as a box opens that box
+ You can assume all keys will be positive integers
+ There can be keys that do not have boxes
+ The first box <code data-beeline-skip="true">boxes[0]` is unlocked
+ Return <code data-beeline-skip="true">True` if all boxes can be opened, else return <code data-beeline-skip="true">False`

```
carrie@ubuntu:~/0x00-lockboxes$ cat main_0.py
#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))

carrie@ubuntu:~/0x00-lockboxes$
```

```
carrie@ubuntu:~/0x00-lockboxes$ ./main_0.py
True
True
False
carrie@ubuntu:~/0x00-lockboxes$
```
