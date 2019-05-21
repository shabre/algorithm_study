from enum import Enum
import queue

class Direction(Enum):
    LEFT = -1
    RIGHT = 1
    SAME = 0


breed_queue = queue.Queue()


class Tree:
    def __init__(self, age):
        self.age = age


class Land:
    def __init__(self, r, c, food):
        self.r = r
        self.c = c
        self.current_food = 5
        self.reserve_food = 0
        self.basic_food = food
        self.trees = []
        self.breed_trees_cnt = 0

    def insert_tree(self, tree):
        idx = 0
        for t in self.trees:
            if tree.age <= t.age:
                self.trees.insert(idx, tree)
                return
            idx += 1
        self.trees.append(tree)

    def spring_process(self):
        for tree in self.trees:
            if tree.age <= self.current_food:
                self.current_food -= tree.age
                tree.age += 1
                if tree.age % 5 == 0:
                    self.breed_trees_cnt += 1
                    if self.breed_trees_cnt == 1:
                        breed_queue.put((self.r, self.c))
            else:
                dieTrees = self.trees[self.trees.index(tree):len(self.trees)]
                for dieTree in dieTrees:
                    self.reserve_food += dieTree.age // 2
                self.trees = self.trees[0:self.trees.index(tree)]
                break

    def summer_process(self):
        self.current_food += self.reserve_food
        self.reserve_food = 0
        self.winter_process()



    def breeding(self):
        for r in Direction:
            if not (self.r + r.value >= 1 and self.r + r.value <= max_size):
                continue
            for c in Direction:
                if r.value == 0 and c.value == 0:
                    continue
                if not (self.c + c.value >= 1 and self.c + c.value <= max_size):
                    continue
                for i in range(self.breed_trees_cnt):
                    land_idx[self.r + r.value][self.c + c.value].insert_tree(Tree(1))

        self.breed_trees_cnt = 0

    def winter_process(self):
        self.current_food += self.basic_food

    def get_alive_tree_cnt(self):
        return len(self.trees)


def fall_process():
    while breed_queue.qsize() > 0 :
        tup = breed_queue.get()
        land_idx[tup[0]][tup[1]].breeding()

def input_case():
    str = input()
    return list(map(int, str.split()))


N, M, K = input_case()# N 컬럼 크기 M 나무 수 K 지난
max_size = N
land_idx = [[0 for col in range(N+1)] for row in range(N+1)]

for i in range(1, N + 1):
    arr = input_case()
    for j in range(1, N + 1):
        land_idx[i][j] = Land(i, j, arr[j-1])

for i in range(M):
    arr = input_case()
    land_idx[arr[0]][arr[1]].insert_tree(Tree(arr[2]))


for i in range(K):
    for r in range(1, N + 1):
        for c in range(1, N + 1):
            land_idx[r][c].spring_process()

    for r in range(1, N + 1):
        for c in range(1, N + 1):
            land_idx[r][c].summer_process()

    fall_process()

alive_tree = 0
for r in range(1, N + 1):
    for c in range(1, N + 1):
        alive_tree += land_idx[r][c].get_alive_tree_cnt()

print(alive_tree)
