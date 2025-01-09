N = int(input())

command = []
num = []

for _ in range(N):
    line = input().split()
    command.append(line[0])
    if line[0] == "push_back" or line[0] == "get":
        num.append(int(line[1]))
    else:
        num.append(0)


arr=[]
for i in range(N):
    if command[i] == 'push_back':
        arr.append(num[i])
    elif command[i] == 'pop_back':
        arr.pop()
    elif command[i] == 'size':
        print(len(arr))
    elif command[i] == 'get':
        print(arr[num[i]-1])