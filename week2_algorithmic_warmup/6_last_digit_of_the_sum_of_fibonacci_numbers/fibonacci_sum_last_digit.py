# Uses python3
import sys
    
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

def get_fibonacci_huge(n,m):
    period = get_period_len(n,m)
    fib = calc_fib(n%period)
    return fib%m


def fibonacci_sum(n):
    fib = get_fibonacci_huge(n+2,10)
    fib = ((fib-1)+10)%10
    return fib;

    
def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current

    return sum % 10

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(fibonacci_sum(n))
