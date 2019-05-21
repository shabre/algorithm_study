list = [2, 3, 4, 5, 6]
for i in list:
    if i > 2:
        print(list.index(i))
        list=list[0:list.index(i)]

        break

print(list)


list = [2, 3, 4, 5, 6]
list = list[4:5]
print(list)
