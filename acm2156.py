cnt = int(input())
arr = []


def get_larger(a, b):
    return a if a > b else b


for i in range(cnt):
    arr.append(int(input()))

n_sum = [0]
s_sum = [arr[0]] #이번값만
d_sum = [0] #전에값까지 더한 값

for i in range(cnt):
    if i == 0:
        pass
    else:
        n_sum.append(get_larger(get_larger(s_sum[i-1], d_sum[i-1]), n_sum[i-1]))
        s_sum.append(n_sum[i-1] + arr[i])
        d_sum.append(s_sum[i-1] + arr[i])

# print(n_sum)
# print(s_sum)
# print(d_sum)

print(get_larger(n_sum[cnt-1], get_larger(d_sum[cnt-1], s_sum[cnt-1])))
