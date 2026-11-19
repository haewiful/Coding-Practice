T = int(input())

for case in range(1, T+1):
    N, K = map(int, input().split())
    data = list(map(int, input().split()))
    dp = [[0 for _ in range(K+1)] for _ in range(N)]

    def dsf(dp, data, idx, K):
        if K==0:
            return 1
        elif K<0:
            return 0
        if idx>=len(data) or idx<0:
            return 0
        if dp[idx][K]>0:
            return dp[idx][K]

        dp[idx][K] = dsf(dp, data, idx+1, K) + dsf(dp, data, idx+1, K-data[idx])
        return dp[idx][K]

    print(f"#{case} {dsf(dp, data, 0, K)}")
