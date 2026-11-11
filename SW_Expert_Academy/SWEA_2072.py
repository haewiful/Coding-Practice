T = int(input())

for test_case in range(1, T+1):
	print(f"#{test_case} ", end='')
	num = list(map(int, input().split()))
	num = [x for x in num if x%2==1]
	print(sum(num))
