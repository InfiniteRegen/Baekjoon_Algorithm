import sys

n = int(sys.stdin.readline().rstrip('\n'))

sum_ary = []

for each in range(0,n):
    int_ary = sys.stdin.readline().rstrip('\n').split(' ')
    sum_ary.append(int(int_ary[0]) + int(int_ary[1]))

for each in sum_ary:
    print each
