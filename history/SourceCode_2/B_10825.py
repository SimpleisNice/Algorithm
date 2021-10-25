tempN = int(input())

tempDic = {}


for i in range(0, tempN):
    info = input().split(' ')
    name = info[0]
    scores = [info[1], info[2], info[3]]

    
    tempDic[name] = scores


print(tempDic)