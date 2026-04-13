while(True):
    n, m = input().split()
    if n == "0" and m == "0":
        break
    n = int(n)
    m = int(m)
    ans = pow(n, m, 10)
    print(ans)