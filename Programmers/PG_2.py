# 바탕화면 정리
def solution(wallpaper):
    min_x = len(wallpaper[0])
    max_x = 0
    min_y = len(wallpaper)
    max_y = 0

    for i, row in enumerate(wallpaper):
        for j, c in enumerate(row):
            if c=='#':
                min_x = min(min_x, j) # 세로
                max_x = max(max_x, j)
                min_y = min(min_y, i) # 가로
                max_y = max(max_y, i)

    answer = [min_y, min_x, max_y+1, max_x+1]
    return answer
