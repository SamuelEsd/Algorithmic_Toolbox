# Uses python3
def calc_fib_aux(n,dic):
    if(n in dic.keys()):
        return dic.get(n)
    else:
        dic[n] = calc_fib_aux(n-1, dic) + calc_fib_aux(n - 2,dic)
        return dic[n]
    
def calc_fib(n):
    
    if (n <= 1):
        return n
    else:
        dic = {0:0,1:1}
        return calc_fib_aux(n - 1, dic) + calc_fib_aux(n - 2,dic)

n = int(input())
print(calc_fib(n))
