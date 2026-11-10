# 컨트롤 제트
def solution(s):
    answer = 0
    prev = 0
    for c in s.split():
        try:
            answer += int(c)
            prev = int(c)
        except:
            answer -= prev
    return answer
