# 1926
N = int(input())

for n in range(1, N+1):
    isClap=False
    tmp = n
    while tmp > 0:
        d = tmp%10
        if d!=0 and d%3==0:
            print("-", end='')
            isClap = True
        tmp=int(tmp/10)
    if not isClap:
        print(int(n), end='')
    print(" ", end='')