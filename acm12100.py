from enum import Enum
import queue


class Direction(Enum):
    UP = 0
    DOWN = 1
    LEFT = 2
    RIGHT = 3


def input_case():
    str = input()
    return list(map(int, str.split()))


def set_merged_queue(arr, i, j, prev, queue):
    if prev == 0:
        prev = arr[i][j]
    else:
        if prev == arr[i][j]:
            queue.put(prev * 2)
            prev = 0
        elif arr[i][j] == 0:
            pass
        else:
            queue.put(prev)
            prev = arr[i][j]
    return prev



def set_new_arr(arr, i, j, value):
    arr[i][j] = value


def get_max_val(arr):
    max_val = 0
    for row in arr:
        for val in row:
            max_val = max(val, max_val)

    return max_val



def move_step(arr, size, direction, step):
    # 처음 시작 전 한쪽으로 미는 푸시작업을 해야한다
    new_arr = [[0 for i in range(size)] for j in range(size)]
    if direction == Direction.UP:
        for i in range(size):
            prev = 0
            q = queue.Queue()
            for j in range(size):
                prev = set_merged_queue(arr, j, i, prev, q)
            if prev > 0:
                q.put(prev)
            for j in range(size):
                if not q.empty():
                    s = q.get()
                    set_new_arr(new_arr, j, i, s)
                else:
                    break

    elif direction == Direction.DOWN:
        for i in range(size):
            prev = 0
            q = queue.Queue()
            for j in reversed(range(size)):
                prev = set_merged_queue(arr, j, i, prev, q)
            if prev > 0:
                q.put(prev)
            for j in reversed(range(size)):
                if not q.empty():
                    set_new_arr(new_arr, j, i, q.get())
                else:
                    break

    elif direction == Direction.LEFT:
        for i in range(size):
            prev = 0
            q = queue.Queue()
            for j in range(size):
                prev = set_merged_queue(arr, i, j, prev, q)
            if prev > 0:
                q.put(prev)
            for j in range(size):
                if not q.empty():
                    set_new_arr(new_arr, i, j, q.get())
                else:
                    break

    elif direction == Direction.RIGHT:
        for i in range(size):
            prev = 0
            q = queue.Queue()
            for j in reversed(range(size)):
                prev = set_merged_queue(arr, i, j, prev, q)
            if prev > 0:
                q.put(prev)
            for j in reversed(range(size)):
                if not q.empty():
                    set_new_arr(new_arr, i, j, q.get())
                else:
                    break
    if step == 5:
        return get_max_val(new_arr)
    else:
        max_val = 0
        for d in Direction:
            val = move_step(new_arr, cnt, d, step + 1)
            max_val = max(val, max_val)
        return max_val





cnt = int(input())
arr = []

for i in range(cnt):
    arr.append(input_case())

max_val = 0
for direction in Direction:
    val = move_step(arr, cnt, direction, 1)
    max_val = max(val, max_val)
print("%d" % max_val)

