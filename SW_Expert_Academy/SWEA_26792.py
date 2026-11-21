T = int(input())

for case in range(1, T+1):
    add, sub = map(int, input().split())
    a = int((add+sub)/2)
    b = int(add - a)
    print(a, b)