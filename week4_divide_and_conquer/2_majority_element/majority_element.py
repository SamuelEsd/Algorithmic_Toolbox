# Uses python3
import sys
import random

def get_majority_element(a, left, right):
    if (right == left):
        return (1,a[right])
    else:
        mid = ((right-left)//2)+left
        ls = get_majority_element(a,left,mid)
        rs = get_majority_element(a,mid+1,right)
        # print("para rangos "+ str(left)+"," +str(right))
        # print("el lado izquierdo nos da ",ls)
        # print("el lado derecho nos da ",rs)
        if (ls == rs and ls == -1):
            return -1
        elif (ls == -1 or rs == -1):
            if (ls != -1):
                reps = ls[0]
                num = ls[1]
                reps += a[mid+1:right+1].count(num)
                # print("   reps ",reps)
                # print("   mitad ",((right+1)-left)//2)
                if(reps > ((right+1)-left)/2):
                    return (reps,num)
                else:
                    return -1
            else:
                reps = rs[0]
                num = rs[1]
                reps += a[left:mid+1].count(num)
                # print("   reps ",reps)
                # print("   mitad ",((right+1)-left)//2)
                if(reps > ((right+1)-left)/2):
                    return (reps,num)
                else:
                    return -1
        else:
            if (ls[1] == rs[1]):
                return (ls[0]+rs[0],ls[1])
            else:
                return -1

def get_majority_el(a):
    a.sort()
    mtn = (0,0)
    for i in a:
        if(i == mtn[0]):
            mtn = (mtn[0],mtn[1]+1)
        else:
            mtn = (i,1)
        if(mtn[1] > len(a)/2):
            return 1
    return 0
    
if __name__ == '__main__':
    # input = sys.stdin.read()
    # n, *a = list(map(int, input.split()))


    # print(a)
    
    ## pruebas
    condition=True
    while condition:
        #n = random.randint(0,22)
        a = [random.randrange(1, 50, 1) for i in range(random.randint(1,300))] 
        n = len(a)
        print("N ",n)
        print(a)
        b = a.copy()
        b.sort()
        print(b)        
        g_m = get_majority_el(a)
        print("with sort ",g_m)
        dac = get_majority_element(a, 0, n-1)
        print("with divide and conquer ",dac)
        if dac != -1:
            if(g_m != 1):
                print("1")
                condition = False
        else:
            print("0")
            if(g_m != 0):
                condition = False

#    print(get_majority_el(a))        
    # if get_majority_element(a, 0, n-1) != -1:
    #     print(1)
    # else:
    #     print(0)

        
