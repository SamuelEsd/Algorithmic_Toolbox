# Uses python3
from sys import stdin

def fibonacci_sum_squares_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current * current

    return sum % 10

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


def fibonacci_sum_squares(n):
    fib1 = get_fibonacci_huge(n,10)
    fib2 = get_fibonacci_huge(n+1,10)
    fib = (fib1*fib2)%10
    return fib;


if __name__ == '__main__':
    n = int(stdin.read())
    print(fibonacci_sum_squares(n))
