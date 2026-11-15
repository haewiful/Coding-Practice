T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N, L = map(int, input().split())
    data = [] # score calory
    print(f"#{test_case}", end=" ")
    for i in range(N):
        data.append(list(map(int, input().split())))

    def get_score(dp, data, L, idx):
        if idx >= len(data) or L <= 0:
            return 0
        if dp[L][idx] > 0:
            return dp[L][idx]

        dp[L][idx] = get_score(dp, data, L, idx + 1)
        if L >= data[idx][1]:
            dp[L][idx] = max(dp[L][idx], get_score(dp, data, L - data[idx][1], idx + 1) + data[idx][0])
        return dp[L][idx]
    # dp = [0 for _ in range(L+1)]  # dp[L] = score
    dp = [[0 for _ in range(N)] for _ in range(L+1)]  # dp[L][ㅑㅇㅌ] = score
    get_score(dp, data, L, 0)
    print(dp[L][0])

