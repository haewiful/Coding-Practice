T = int(input())
for test_case in range(1, T + 1):
	dic = {}
	num = int(input())
	arr = list(map(int, input().split()))
	s = -1
	max_n=0
	for a in arr:
		dic[a] = dic.get(a,0)+1
		if dic[a]>max_n:
			max_n=dic[a]
			s=a
		elif dic[a]==max_n:
			if s<a:
				max_n=dic[a]
				s=a
	print(f"#{test_case}", s)
