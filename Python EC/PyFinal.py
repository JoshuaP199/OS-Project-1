import threading

N = int(input("Number to use in summation: "))
M = int(input("Number of threads to use: "))

q = (N//M)
rem = N%M

def runner(X, Y, Z):
    if (i == M-1):
        sum = 0
        for p in range((N-lb)+1):
            sum = sum + (lb+p)
        print("sum of ", lb, " to ", ub, " = ", sum)
        holder += sum
        print(holder)
    else:
        sum = 0
        for p in range(q+1):
            sum = sum + (lb+p)
        print("sum of ", lb, " to ", ub, " = ", sum)
        holder += sum
        print(holder)
    return holder
    
if __name__ == "__main__": 
    for i in range(M):
        if i == 0:
            lb = 1
            ub = lb + (q-1)
            print(lb, " ", ub)
        elif (i == M-1):
            ub = N
            lb = (ub - (q+rem))
            print(lb, " ", ub)
        else:
            lb = 1 + (q*i)
            ub = lb + (q-1)
            print(lb, " ", ub)
        a1= threading.Thread(target=runner, args=(lb,ub,i)) 
        a1.start()
        a1.join() 
        holder += holder
    print('Sum of 1 to ', N, ' = ', holder)
    print("Done!") 
