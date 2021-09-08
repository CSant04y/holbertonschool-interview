# 0x06. Log Parsing


## Requirements
### General
  + Allowed editors: `vi`, `vim`, `emacs`
  + All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
  + All your files should end with a new line
  + The first line of all your files should be exactly `#!/usr/bin/python3`
  + A `README.md` file, at the root of the folder of the project, is mandatory
  + Your code should use the `PEP 8` style (version 1.7.x)
  + All your files must be executable
  + The length of your files will be tested using `wc`


## 0. Log parsing
Write a script that reads `stdin` line by line and computes metrics:

Write a script that reads `stdin` line by line and computes metrics:
  + Input format: `&lt;IP Address&gt; - [&lt;date&gt;] "GET /projects/260 HTTP/1.1" &lt;status code&gt; &lt;file size&gt;` (if the format is not this one, the line must be skipped)
  + After every 10 lines and/or a keyboard interruption (`CTRL + C`), print these statistics from the beginning:
    + Total file size: `File size: &lt;total size&gt;`
    + where `&lt;total size&gt;` is the sum of all previous `&lt;file size&gt;` (see input format above)
    + Number of lines by status code: 
      + possible status code: `200`, `301`, `400`, `401`, `403`, `404`, `405` and `500`
      + if a status code doesn’t appear or is not an integer, don’t print anything for this status code
      + format: `&lt;status code&gt;: &lt;number&gt;`
      + status codes should be printed in ascending order
    + possible status code: `200`, `301`, `400`, `401`, `403`, `404`, `405` and `500`
    + if a status code doesn’t appear or is not an integer, don’t print anything for this status code
    + format: `&lt;status code&gt;: &lt;number&gt;`
    + status codes should be printed in ascending order

**Warning:** In this sample, you will have random value - it’s normal to not have the same output as this one.

```
alexa@ubuntu:~/0x06-log_parsing$ cat 0-generator.py
#!/usr/bin/python3
import random
import sys
from time import sleep
import datetime

for i in range(10000):
    sleep(random.random())
    sys.stdout.write("{:d}.{:d}.{:d}.{:d} - [{}] \"GET /projects/260 HTTP/1.1\" {} {}\n".format(
        random.randint(1, 255), random.randint(1, 255), random.randint(1, 255), random.randint(1, 255),
        datetime.datetime.now(),
        random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
        random.randint(1, 1024)
    ))
    sys.stdout.flush()

alexa@ubuntu:~/0x06-log_parsing$ ./0-generator.py | ./0-stats.py 
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
File size: 11320
200: 3
301: 2
400: 1
401: 2
403: 3
404: 4
405: 2
500: 3
File size: 16305
200: 3
301: 3
400: 4
401: 2
403: 5
404: 5
405: 4
500: 4
^CFile size: 17146
200: 4
301: 3
400: 4
401: 2
403: 6
404: 6
405: 4
500: 4
Traceback (most recent call last):
  File "./0-stats.py", line 15, in <module>
Traceback (most recent call last):
  File "./0-generator.py", line 8, in <module>
    for line in sys.stdin:
KeyboardInterrupt
    sleep(random.random())
KeyboardInterrupt
alexa@ubuntu:~/0x06-log_parsing$ 
```