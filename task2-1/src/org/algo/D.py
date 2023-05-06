from collections import deque

d = deque()

q = int(input())

for i in range(q):
    qi = list(map(int, input().split()))

    if qi[0] == 1:
        if len(d) != 0 and d[len(d) - 1][0] == qi[1]:
            el = d.pop()
            d.appendleft((qi[1], qi[2] + el[1]))
        else:
            d.appendleft((qi[1], qi[2]))
    else:
        sum = 0
        num = qi[1]
        while num > 0:
            el = d.pop()
            if el[1] > num:
                d.append((el[0], el[1] - num))
                sum += num * el[0]
            else:
                sum += el[1] * el[0]
            num -= el[1]
        print(sum)
