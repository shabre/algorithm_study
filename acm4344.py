def input_case():
    str = input()
    return list(map(int, str.split()))


def get_sum(arr):
    sum = 0
    size = arr[0]
    for i in range(1, size+1):
        sum += arr[i]
    return sum


def get_over_avg(arr, sum):
    size = arr[0]
    over_age_cnt = 0
    for i in range(1, size+1):
        if sum < arr[i] * size:
            over_age_cnt += 1

    return round(float(over_age_cnt) * 100 / size, 3)

case = int(input())

for i in range(case):
    arr = input_case()
    print("%.3f" % get_over_avg(arr, get_sum(arr)), end="%\n")
