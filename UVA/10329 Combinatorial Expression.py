import math

while True:
    try:
        n, m = input().split()
        n = int(n)
        m = int(m)
        nom = 1
        den = 1
        for i in range(n):
            a, b = input().split()
            a = int(a)
            b = int(b)
            nom *= math.comb(a, b)
        for i in range(m):
            a, b = input().split()
            a = int(a)
            b = int(b)
            den *= math.comb(a, b)
        if nom % den != 0:
            print(0)
            continue;
        ans = nom // den
        st = str(ans)
        if len(st) > 100:
            print(-1)
            continue
        print(ans)
    except EOFError:
        break