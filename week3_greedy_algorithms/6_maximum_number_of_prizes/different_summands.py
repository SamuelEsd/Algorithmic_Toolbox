# Uses python3
import sys

def optimal_summands(n):
    summands = [1]
    count = 2
    candies_left = n-1
    while(count <= candies_left):
        candies_left -= count
        summands.append(count)
        count += 1
    summands[len(summands)-1] += candies_left
    #write your code here
    return summands

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    summands = optimal_summands(n)
    print(len(summands))
    for x in summands:
        print(x, end=' ')
