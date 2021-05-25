# Uses python3
import sys

def calc_fib_aux(n,dic):
    if(n in dic.keys()):
        return dic.get(n)
    else:
        dic[n] = calc_fib_aux(n-1, dic) + calc_fib_aux(n - 2,dic)
        return dic[n]
    
def calc_fib(n):
    a = 1
    b = 1
    if (n == 0):
        return 0
    elif (n < 3):
        return b
    else:
        n -= 2
        while(n > 0):
            temp = b
            b = a + b
            a = temp
            n -= 1
        return b

def get_period_len(n,m):
    a = 1
    b = 1
    counter = 1
    while(a != 0 or b != 1):
        temp = b
        b = (a + b)%m
        a = temp
        counter +=1
    return counter

def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m

def get_fibonacci_huge(n,m):
    period = get_period_len(n,m)
    fib = calc_fib(n%period)
    return fib%m

if __name__ == '__main__':
    input = sys.stdin.read();
    n, m = map(int, input.split())
    print(get_fibonacci_huge(n, m))
#    print("Naive ",get_fibonacci_huge_naive(n, m))
#    print("Mine ",get_fibonacci_huge(n, m))
