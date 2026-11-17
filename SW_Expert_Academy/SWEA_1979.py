# 1979
T = int(input())

for case in range(1, T+1):
    N, K = map(int, input().split())
    data=[]
    cnt=0
    for i in range(N):
        data.append(list(map(int, input().split())))
    for i in range(N):
        ver = 0
        hor = 0
        for j in range(N):
            if data[i][j]==1:
                hor+=1
            else:
                if hor==K:
                    cnt+=1
                hor=0
            if data[j][i]==1:
                ver+=1
            else:
                if ver==K:
                    cnt+=1
                ver=0
        if ver==K:
            cnt+=1
        if hor==K:
            cnt+=1
    print(f"#{case} {cnt}")