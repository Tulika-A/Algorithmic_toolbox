# Uses python3
import sys
import copy


def calc_min(op_list):
    m = sys.maxsize
    for i in range(3):
        if(op_list[i] < m):
            m = op_list[i]
            index = i
    return[m,index+1]


def optimal_sequence(n):
    minNumOperations = [sys.maxsize]*(n+1)
    minNumOperations[0] = 0
    minNumOperations[1] = 0
    sequence = dict()

    for x in range(1,n+1):
        current = copy.deepcopy(x)
        operations1 = sys.maxsize
        operations2 = sys.maxsize
        operations3 = sys.maxsize
        sequence[current] = list()
        sequence[current].append(current)
        if(x > 1):
            if(x % 3 == 0):
                operations3 = minNumOperations[int(x/3)] + 1
               
            if(x % 2 == 0):
                operations2 = minNumOperations[int(x/2)] + 1
                

            operations1 = minNumOperations[x - 1] + 1
            

            [minNumOperations[current], index] = calc_min([operations1, operations2 , operations3])
            
            if index == 1:
                sequence[current].append(x - 1)
            if index == 2:
                sequence[current].append(x/2)
            if index == 3:
                sequence[current].append(x/3)
    finalSequence = list()
    finalSequence.append(n)
    v = sequence[n]
    while(v[1] > 1):
        finalSequence.append(int(v[1]))
        v = sequence[v[1]]
    finalSequence.append(1)    
        
    return reversed(finalSequence)

input = sys.stdin.read()
n = int(input)
sequence = list(optimal_sequence(n))
##sequence = optimal_sequence(n)
##print(sequence)
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
