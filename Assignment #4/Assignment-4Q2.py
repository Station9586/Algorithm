# Just run very long time, and didn't get any answer
def fib(a):
    if (a == 1 or a == 2):
        return 1
    return fib(a - 1) + fib(a - 2)


# print(fib(70))

f = [0 for _ in range(1000001)]
f[0] = 1
f[1] = 1

for i in range(2, 1000001):
    f[i] = f[i - 1] + f[i - 2]

print(f[1000000])
