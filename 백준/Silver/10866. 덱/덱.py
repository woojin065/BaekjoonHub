from collections import deque
import sys

dq = deque()
n = int(input())

for i in range(n):
    s = sys.stdin.readline().split()

    if s[0] == "push_front":
        dq.appendleft(s[1])
    elif s[0] == "push_back":
        dq.append(s[1])
    elif s[0] == "pop_front":
        if dq:
            print(dq[0])    
            dq.popleft()
        else:
            print("-1")
    elif s[0] == "pop_back":
        if dq:
            print(dq[len(dq) - 1])    
            dq.pop()
        else:
            print("-1")
    elif s[0] == "size":
        print(len(dq))
    elif s[0] == "empty":
        if dq:
            print("0")
        else:
            print("1")
    elif s[0] == "front":
        if dq:
            print(dq[0])
        else:
            print("-1")
    elif s[0] == "back":
        if dq:
            print(dq[len(dq) - 1])
        else:
            print("-1")