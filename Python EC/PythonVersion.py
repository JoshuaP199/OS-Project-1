import threading

N = int(input("Number to use in summation: "))
M = int(input("Number of threads to use: "))

lb = 1
q = (N//M)
rem = N%M
holder = 0

for i in range(M):
    if (i == M-1):
        ub = N
        sum = 0
        for p in range((N-lb)+1):
            sum = sum + (lb+p)
    else:
         ub = lb + q
         sum = 0
         for p in range(q+1):
             sum = sum + (lb+p)
    print("sum of ", lb, " to ", ub, " = ", sum)
    lb = ub +1
    holder += sum

print('Sum of 1 to ', N, ' = ', holder)
