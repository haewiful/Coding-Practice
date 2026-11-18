T = int(input())

for case in range(1, T+1):
    data = list(map(int, input().split()))
    print(f"#{case} {int(round(sum(data)/len(data), 0))}")