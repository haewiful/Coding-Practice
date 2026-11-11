cases = int(input())

for i in range(cases):
	print(f'#{i+1}')
	n = int(input())
	i=j=0
	arr = [[0 for _ in range(n)] for _ in range(n)]
	for k in range(1, n**2+1):
		#print(f'arr[{i}][{j}]={k}')
		arr[i][j]=k
		if j+1 < n and arr[i][j+1]==0:
			j+=1
		elif i+1 < n and arr[i+1][j]==0:
			i+=1
		elif j-1>=0 and arr[i][j-1]==0:
			j-=1
		else:
			i-=1
	for row in arr:
		print(*row)
