
list1 = []
list2 = []

f = open("input.txt", "r")
for line in f:
    #print(line.strip())
    test = line.strip().split("   ")
    list1.append(int(test[0]))
    list2.append(int(test[1]))
    print(list1[len(list1)-1], list2[len(list2)-1])

list1.sort()
list2.sort()
sum = 0
for i in range(len(list1)):
    sum += abs(list1[i] - list2[i])
    
print(sum)

#answer: 1222801