T = int(input())

for case in range(1, T+1):
    S = list(map(int, list(input())))
    valid = True
    for i in range(10):
        if i in S:
            idx = S.index(i)
            if i in S[idx+1:]:
                second = S.index(i, idx+1)
                if i in S[second+1:]:
                    valid = False
                    break
                if second-idx-1 != i:
                    valid = False
                    break
            else:
                valid=False
                break
    if valid:
        print("yes")
    else:
        print("no")
