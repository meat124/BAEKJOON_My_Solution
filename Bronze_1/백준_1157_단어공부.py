str = input().upper()
str_list = list(set(str))
cnt_list = []  # 각 알파벳이 몇 개 씩 있는지 저장
for i in str_list:
    cnt_list.append(str.count(i))
if cnt_list.count(max(cnt_list)) > 1:
    print("?")
else:
    print(str_list[cnt_list.index(max(cnt_list))])
