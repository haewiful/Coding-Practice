for n in range(1, 11):
	print(f'#{n}', end=' ')
	b_num = int(input())
	height = list(map(int, input().split()))
	provided=0
	lowest=0
	for idx in range(2, b_num-2):
		if lowest < height[idx+1]:
			lowest = height[idx+1]
		if lowest < height[idx+2]:
			lowest = height[idx+2]
		# calculate household
		provided += max(0, height[idx]-lowest)
		lowest = max(height[idx], height[idx-1])
	print(provided)
