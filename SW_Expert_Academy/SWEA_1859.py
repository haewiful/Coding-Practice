T = int(input())
for test_case in range(1, T + 1):
	n = int(input())
	prices = list(map(int, input().split()))

	print(f'#{test_case}', end=' ')
	profit = 0
	prev_max = prices[-1]
	for idx in range(len(prices)-2, -1, -1):
		if prices[idx] < prev_max:
			profit += prev_max - prices[idx]
		else:
			prev_max = prices[idx]
	print(profit)

        
