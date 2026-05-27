f = [0] * 2005

f[1] = 1
f[2] = 3

for i in range(3, 2005):
    f[i] = 3*f[i-1] - f[i-2]

while True:
    n = int(input())
    if(n == 0): break
    print(f[n])