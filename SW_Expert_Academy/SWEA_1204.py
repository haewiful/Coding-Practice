T = int(input())
for test_case in range(1, T + 1):
	dic = {}
	num = int(input())
	arr = list(map(int, input().split()))
	for a in arr:
		dic[a] = dic.get(a,0)+1
	print(f"#{test_case}", max(dic.items(), key=lambda item: item[1])[0])
