# 1208

for case in range(1, 11):
    dump = int(input())
    data = list(map(int, input().split()))
    for i in range(dump):
        data[data.index(max(data))]-=1
        data[data.index(min(data))]+=1

    print(f"#{case} {max(data)-min(data)}")