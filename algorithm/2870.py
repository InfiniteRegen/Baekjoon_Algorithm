from sys import stdin
import re

a = []
n = int(stdin.readline())

for x in range(0, n):
    maxVal = 0
    b = stdin.readline()
    each = re.findall(r'\d+|[a-z]+', b)

    for line in each:
        if line.isdigit():
            a.append(int(line))

other = sorted(a, reverse = False)

for x in other:
    print x
