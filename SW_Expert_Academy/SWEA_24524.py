T = int(input())

for case in range(1, T+1):
    N = int(input())
    data = list(map(int, input().split()))
    total=0
    max_idx=None
    max_diff=0
    for i in range(1, N-1):
        diff = abs(data[i]-data[i-1]) + abs(data[i+1]-data[i]) - abs(data[i+1]-data[i-1])
        if diff > max_diff:
            max_diff = diff
            max_idx = i
        total += abs(data[i]-data[i-1])
    total += abs(data[-1]-data[-2])
    total -= max_diff
    print(total)
