
while 1:
    try:
        a, b = map(int,input().split(' '))
        print(a+b)
    except:
        break

while True:
    try:
        t = int(input())
        for i in range(t):
            a,b = map(int,input().split())
            print(a + b)
    except:
        break

while 1 :
    a, b = map(int, input().split(' '))
    if a == 0 and b == 0:
        break
    print(a + b)

while 1:
    l = list(map(int, input().split(' ')))
    if len(l) == 1 and l[0] == 0:
        break
    print(sum(l[1:]))

t=int(input())
for i in range(t):
    n=list(map(int,input().split()))
    if n[0]==0:
        break
    print(sum(n)-n[0])

while True:
    try:
        a=list(map(int,input().split()))
        if a[0]!=0:
            sum_=0
            for i in range(1,a[0]+1):
                sum_+=a[i]
            print(sum_)
    except:
        break

while True:
    try:
        a=list(map(int,input().split()))
        print(sum(a))
    except:
        break



import sys
if __name__ == "__main__":
    #n = input()
    n = int(sys.stdin.readline())
    a = sys.stdin.readline().strip().split(" ")
    a.sort()
    for i in range(n):
        print(a[i],end=" ")

from fileinput import input
for line in input():
    a = line.split()
    a = sorted(a)
    s = ''
    for i in range(len(a)-1):
        s+=a[i]+' '
    s += a[-1]
    print(s)

import sys
for line in sys.stdin:
    l = sorted(line.strip().split(','))
    print(','.join(l))

import sys
if __name__ == "__main__":
    for line in sys.stdin.readlines():
        a,b = map(int, line.strip().split())
        print(a+b)