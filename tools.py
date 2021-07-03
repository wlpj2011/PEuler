import math

def fibo(n,postit):
    if n in postit:
        answer = postit[n]
    else:
        if n < 2:
            answer =  n
        else:
            answer = fibo(n-1,postit)+fibo(n-2,postit)
        postit[n] = answer
    return answer

def isPrime(n):
    for i in range(2,math.floor(math.sqrt(n))+1):
        if n%i==0:
            return False
    return True
