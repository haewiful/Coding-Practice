T = int(input())

months = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
for case in range(1, T+1):
    date = input()
    year = date[:4]
    mon = date[4:6]
    day = date[6:]
    if int(mon)<1 or int(mon)>12 or months[int(mon)] < int(day):
        print(f"#{case}", -1)
    else:
        print(f"#{case} {year}/{mon}/{day}")
