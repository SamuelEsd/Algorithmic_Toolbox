#Uses python3

import sys

def greater_than(a,b):
    max_len = max(len(a),len(b))
    min_len = min(len(a),len(b))
    count = 0
    while(count < max_len):
        if(count < min_len):
            if(a[count] == b[count]):
                count += 1
                continue
            elif(a[count] < b[count]):
                return false
        else:
            if(len(a) > len(b)):
                max_b = max()
                while()
def largest_number(a):
    #write your code here
    print(a)
    a.sort(reverse=True)
    res = ""
    for x in a:
        res += x
    return res

if __name__ == '__main__':
    input = sys.stdin.read()
    data = input.split()
    a = data[1:]
    print(largest_number(a))
    
