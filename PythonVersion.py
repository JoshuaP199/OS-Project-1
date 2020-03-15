import threading

sum = 0
finalSUM = 0
lb = 1
ub = 0

N = input("Number to use in summation: ")
M = input("Number of threads to use: ")

q = (N/M)-1
rem = N%M

for i in range(M+1):
    ub = lb + q
    cur = lb
    sum = 0

    for p in range(q):
        sum = sum + (lb+p)
    
    print("sum of " + cur + " to " + ub + " = " + sum + "\n")
    lb = ub +1
