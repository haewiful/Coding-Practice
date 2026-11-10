# 약수의 개수와 덧셈
import math
def solution(left, right):
    answer = 0
    for n in range(left, right+1, 1):
        if math.sqrt(n) % 1 != 0:
            answer += n
        else:
            answer -= n
    return answer

