# Uses python3
import sys
import math

def gcd_naive(a, b):
    while (b != 0):
        res = a%b
        a = b
        b = res
    return a

if __name__ == "__main__":
#    input = sys.stdin.read()
    a, b = map(int, input().split())
    print(gcd_naive(max(a, b),min(a,b)))
