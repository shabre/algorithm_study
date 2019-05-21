def input_case():
    str = input()
    return list(map(int, str.split()))
a, b = input_case()
print(a-b)
