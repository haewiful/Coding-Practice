T = int(input())

for case in range(1, T+1):
    N = int(input())
    row = [-1 for _ in range(N)]
    # col = [-1 for _ in range(N)]

    def dfs(idx):
        if idx == N:
            return 1

        cnt=0
        def is_valid(r, c):
            for i in range(r):
                if row[i]==c:
                    return False
                if abs(r-i) == abs(c-row[i]):
                    return False
            return True

        for i in range(N):
            if is_valid(idx, i):
                row[idx]=i
                cnt += dfs(idx+1)
        return cnt


    print(f"#{case} {dfs(0)}")
