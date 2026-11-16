T = int(input())

for case in range(1, T + 1):
    N, M = map(int, input().split())
    print(f"#{case}", end=" ")
    data = [[0 for _ in range(N)] for _ in range(N)]
    fly = [[0 for _ in range(N)] for _ in range(N)]
    max_n = 0
    for i in range(N):
        data[i] = list(map(int, input().split()))
        for j in range(N):
            for k in range(M):
                if i+k >= N:
                    continue
                for l in range(M):
                    if j + l < N:
                        fly[i+k][j+l] += data[i][j]
                    else:
                        break
        max_n = max(max_n, max(fly[i]))
    print(max_n)