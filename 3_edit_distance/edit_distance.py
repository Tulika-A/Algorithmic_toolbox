# Uses python3
def edit_distance(s, t):
    D = [[0 for j in range(len(t)+1)] for i in range(len(s)+1)]
    
    for i in range(len(s) + 1):
        D[i][0] = i
        
    for j in range(len(t) + 1):
        
        D[0][j] = j

    
            
    for j in range(1, len(t) + 1):
        for i in range(1, len(s) + 1):
            
            ins = D[i][j - 1] + 1
            d = D[i  - 1][j] + 1
            m = D[i - 1][ j - 1]
            mm = D[i - 1][ j - 1] + 1
            if(s[i-1] == t[j-1]):
                 D[i][j] = min(ins,min(d,m))
            else:
                 D[i][j] = min(ins, min(d,mm))
            
    return D[len(s)][len(t)]

if __name__ == "__main__":
    print(edit_distance(input(), input()))
