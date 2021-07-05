import sys
from tools import factors,sumnPowk,primeFactors

def solution(n):
    i = 0
    numFac = 1
    while numFac < n:
        i+=1
        primeFaci = primeFactors(i)
        primeFacis = primeFactors(i+1)
        primeFacTri = []
        numFac = 1
        for j in range(max(len(primeFaci),len(primeFacis))):
            if j >= len(primeFaci):
                primeFaci.append(0)
            if j >= len(primeFacis):
                primeFacis.append(0)
            numFac *= (primeFaci[j]+primeFacis[j]+1-int(j==0))
    return sumnPowk(i,1)

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: " + str(solution(n)))
