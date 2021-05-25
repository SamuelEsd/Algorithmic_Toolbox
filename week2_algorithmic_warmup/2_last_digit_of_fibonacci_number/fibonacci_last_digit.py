# Uses python3
import sys

def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for i in range(n - 1):
        previous, current = current%10, (previous + current)%10

    return current % 10

if __name__ == '__main__':
    #input = sys.stdin.read()
    n = int(input())
    print(get_fibonacci_last_digit_naive(n))

# Uses python3
# def calc_fib_aux(n,dic):
#     if(n in dic.keys()):
#         return dic.get(n)
#     else:
#         dic[n] = calc_fib_aux(n-1, dic) + calc_fib_aux(n - 2,dic)
#         return dic[n]
    
# def calc_fib(n):
    
#     if (n <= 1):
#         return n
#     else:
#         dic = {0:0,1:1}
#         return calc_fib_aux(n - 1, dic) + calc_fib_aux(n - 2,dic)

# n = int(input())
# print(calc_fib(n))
