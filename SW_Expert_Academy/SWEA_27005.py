T = int(input())

for _ in range(T):
    n = int(input())
    arr = [1, 1]
    for i in range(2, n+1):
        invalid = []
        for j in range(1, i//2+1):
            # print(f"({i}, {j})={2*arr[i-j]-arr[i-2*j]}")
            invalid.append(2*arr[i-j]-arr[i-2*j])
        invalid.sort()
        # print("invalid:", invalid)
        min_a = max(invalid)+1
        i=1
        while i < max(invalid):
            if i not in invalid:
                if min_a > i:
                    min_a=i
                break
            i+=1
        arr.append(min_a)
    print(arr[n])
