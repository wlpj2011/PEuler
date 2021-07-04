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

def isPalin(n):
    n = str(n)
    k = len(n)
    for i in range(k//2):
        if n[i]!=n[k-i-1]:
            return False
    return True

def sumnPowk(n,k):
    if k == 1:
        return n*(n+1)//2
    elif k == 2:
        return n*(n+1)*(2*n+1)//6
    elif k == 3:
        return math.pow(sumnPowk(n,2),2)
    else:
        sum = 0
        for i in range(n+1):
            sum += math.pow(i,k)
        return sum

def factors(n):
    result = []
    for i in range(1,n+1):
        if n%i==0:
            result.append(i)
    return result
