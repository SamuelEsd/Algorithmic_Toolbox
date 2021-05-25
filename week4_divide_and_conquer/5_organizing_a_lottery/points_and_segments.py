# Uses python3
import sys

def fast_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    starts.sort()
    ends.sort()
    points.sort()

    i = 0
    j = 0
    k = 0
    segmentos_activos = {}
    while(i <len(starts) or j < len(ends) or k < len(points) ):
        # Si ya pasaste todos los fines de los segmentos
        # O todos los puntos
        # te sales
        if(j >= len(ends) or k >= len(points)):
            break
        # si ya no hay inicios ve sacando puntos
        # y fines hasta que alguno de los dos se termine
        if(i >= len(starts)):
            # si sale un end
            if((ends[j])[0] < (points[k])[0]):
                # eliminamos el segmento de los activos
                segmentos_activos.pop(str((ends[j])[1]))
                j += 1
            else:
                # si el punto sale entonces sumamos los segmentos
                # con los que intersecta (activos)
                # y quitamos el punto
                cnt[(points[k])[1]] += len(segmentos_activos)
                k += 1;
        else:
            # si hay algun inicio igual o menor a finales o puntos
            # lo agregamos a segmentos activos
            if((starts[i])[0] <= (ends[j])[0] and (starts[i])[0] <= (points[k])[0]):
                segmentos_activos[str((starts[i])[1])] = "activo"
                i += 1
            else:
                if((ends[j])[0] < (points[k])[0]):
                    # eliminamos el segmento de los activos
                    segmentos_activos.pop(str((ends[j])[1]))
                    j += 1
                else:
                    # si el punto sale entonces sumamos los segmentos
                    # con los que intersecta (activos)
                    # y quitamos el punto
                    cnt[(points[k])[1]] += len(segmentos_activos)
                    k += 1;
    return cnt

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    starts1 = [(starts[i],i) for i in range(len(starts))]
    ends   = data[3:2 * n + 2:2]
    ends1 = [(ends[i],i) for i in range(len(ends))]
    points = data[2 * n + 2:]
    points1 = [(points[i],i) for i in range(len(points))]
    #use fast_count_segments
    cnt = fast_count_segments(starts1, ends1, points1)
    for x in cnt:
        print(x, end=" ")
    print()
    # cnt = naive_count_segments(starts, ends, points)
    # for x in cnt:
    #     print(x, end=' ')

