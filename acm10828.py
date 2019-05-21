class Stack:
    def __init__(self):
        self.stack = []
        self.size = 0

    def push(self, num):
        self.stack.append(num)
        self.size += 1

    def pop(self):
        if self.size == 0:
            return -1
        else:
            self.size -= 1
            return self.stack.pop()

    def getSize(self):
        return self.size

    def empty(self):
        if self.size == 0:
            return 1
        else:
            return 0

    def top(self):
        if self.size == 0:
            return -1
        else:
            return self.stack[self.size - 1]


stack = Stack()
cnt = input()

for i in range(int(cnt)):
    cmd = input().split(' ')
    if cmd[0] == 'push':
        stack.push(int(cmd[1]))
    elif cmd[0] == 'pop':
        print(stack.pop())
    elif cmd[0] == 'top':
        print(stack.top())
    elif cmd[0] == 'size':
        print(stack.getSize())
    elif cmd[0] == 'empty':
        print(stack.empty())
