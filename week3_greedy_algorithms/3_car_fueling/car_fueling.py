# python3
import sys


def compute_min_refills(distance, tank, stops):
    me = 0
    pointer = 1
    new_pointer = -1
    while(distance != me):
        if stop[pointer] - stop[me] <= tank and pointer < len(stops):
            new_pointer = pointer
        else:
            if (new_pointer = -1):
                return -1
            else:
                me = new_pointer
                pointer = me
                new_pointer = -1
        pointer++
            # write your code here
    return -1

if __name__ == '__main__':
    d, m, _, *stops = map(int, sys.stdin.read().split())
    print(compute_min_refills(d, m, stops.append(d)))
