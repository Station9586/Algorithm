import time
import matplotlib.pyplot as plt
import math
# in recursive


def fib(a) -> int:
    if (a == 1 or a == 2):
        return 1
    return fib(a - 1) + fib(a - 2)


x = []
y = []
# 因為n = 50時就要跑46分鐘以上, n = 60要4天, n = 70要492天...，因此遞迴的n只用到40
for i in range(10, 41, 10):
    # x.append(i)
    start = time.process_time()
    print(f"{i}: {fib(i)}")
    end = time.process_time()
    # y.append(end - start)
    print(f"executed time: {end - start} s")

# 因為數字太大，所以後續的時間用算的來繪圖
for i in range(1, 101):
    x.append(i)
    y.append(math.pow(1.618, i) / math.pow(10, 7))

x2 = []
y2 = []
f = [1, 1]

t = 0
for j in range(2, 101):
    x2.append(j)
    # for _ in range(1):
    f = [0 for _ in range(101)]
    f[0] = 1
    f[1] = 1
    t = 0
    for _ in range(100):
        start = time.process_time()
        for i in range(2, j):
            f[i] = f[i - 1] + f[i - 2]
        end = time.process_time()
        t += end - start
    t /= 100
    y2.append(t)
    print(f"{j}: {f[j - 1]}")
    print(f"Executed time: {(t) * 1000} ms")


plt.plot(x, y)
plt.title("Recursive time executed")
plt.xlabel("number of n (1 ~ 100)")
plt.ylabel("Executed time (s)")
plt.show()

plt.plot(x2, y2)
plt.title("Dynamic programming time executed")
plt.xlabel("number of n (1 ~ 100)")
plt.ylabel("Executed time (ms)")
plt.show()

x3 = []
y3 = []
for i in range(1, 101):
    x3.append(i)
    y3.append(1.618 * i / 1e7 * 1e3)
plt.plot(x3, y3)
plt.title("Dynamic programming time executed (Calculate)")
plt.xlabel("number of n (1 ~ 100)")
plt.ylabel("Executed time (ms)")
plt.show()
