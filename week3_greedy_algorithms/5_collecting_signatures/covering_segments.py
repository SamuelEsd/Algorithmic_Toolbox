# Uses python3
import sys
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def optimal_points(segments):
    segments.sort()
    counter = 1

    s = segments[0].start
    e = segments[0].end

    points = []    
    
    while( counter < len(segments) ):
        if (segments[counter].start >= s and segments[counter].start <= e ):
            s = max(segments[counter].start, s)
            e = min(segments[counter].end, e)
        else:
            points.append(s)
            s = segments[counter].start
            e = segments[counter].end
        if(counter == len(segments) - 1):
            points.append(s)
        counter += 1
    return points

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *data = map(int, input.split())
    segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    points = optimal_points(segments)
    print(len(points))
    print(*points)
