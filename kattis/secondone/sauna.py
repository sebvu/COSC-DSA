cases = int(input())

lists = {}
ranges = []
c = 0

for i in range(cases):
    a, b = map(int, input().split())
    c += 1
    lists[a] = c
    c += 1
    lists[b] = c
    ranges.append((a, b))

answers = []

for i in lists:
    fits_all = True
    for r in ranges:
        if not (r[0] <= i <= r[1]):
            fits_all = False
            break
    if fits_all:
        answers.append(i)


answers = sorted(answers)

if len(answers) > 0:
    print(f"{lists[answers[0]]} {answers[0]}")
else:
    print("bad news")
