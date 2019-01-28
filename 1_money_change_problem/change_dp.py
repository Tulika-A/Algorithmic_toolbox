# Uses python3
import sys


def get_change(money):
    coins = [1,3,4]
    minNumCoins = list()
    minNumCoins.append(0)
    for m in range(1, money+1):
        minNumCoins.append(sys.maxsize)
        for i in coins:
            if m>=i:
                numCoins = minNumCoins[m-i] + 1
                if numCoins < minNumCoins[m]:
                    minNumCoins[m] = numCoins
                
    return minNumCoins[m]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
