# Uses python3
import sys


def gcd_naive(a, b):
    while (b != 0):
        res = a%b
        a = b
        b = res
    return a

def lcm_naive(a, b):
    return a*b//gcd_naive(max(a,b),min(a,b))


if __name__ == '__main__':
#    input = sys.stdin.read()
    a, b = map(int, input().split())
    print(lcm_naive(a, b))

