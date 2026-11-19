T = int(input())

for case in range(1, T+1):
    profit=0
    N = int(input())
    data = []
    for _ in range(N):
        data.append(list(map(int, list(input()))))
    for i in range(N//2):
        start = N//2-i
        end = N//2+i+1
        profit += sum(data[i][start:end])
        profit += sum(data[N-1-i][start:end])
    profit += sum(data[N//2])
    print(f"#{case} {profit}")