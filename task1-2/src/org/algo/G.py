from functools import cmp_to_key


def compare(x, y):
    if x[1] > y[1]:
        return 1
    elif x[1] < y[1]:
        return -1
    if x[0] == '-' and y[0] == '+':
        return 1
    return -1


args = input().split(' ')

n = int(args[0])
m = int(args[1])

intervals = []
dots = []

for i in range(n):
    args = input().split(' ')
    intervals.append(('+', int(args[0])))
    intervals.append(('-', int(args[1])))

args = input().split(' ')
for i in range(m):
    dots.append(int(args[i]))

intervals = sorted(intervals, key=cmp_to_key(compare))

counter = 0
dotsPointer = 0

for pair in intervals:
    sym = pair[0]
    index = pair[1]
    if sym == '+':
        while dotsPointer < m and dots[dotsPointer] < index:
            print(f'{counter} ', end='')
            dotsPointer += 1
        counter += 1
    else:
        while dotsPointer < m and dots[dotsPointer] <= index:
            print(f'{counter} ', end='')
            dotsPointer += 1
        counter -= 1

