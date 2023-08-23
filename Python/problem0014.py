import sys
from tools import collatz

def solution(n):
    sequence = []
    longest = 1
    longestlength = len(sequence)
    for i in range(1,n):
        j = i
        sequence = []
        coli = i
        while coli!=1:
            coli = collatz(i)
            sequence.append(coli)
            i = coli
        if len(sequence) > longestlength:
            longest = j
            longestlength = len(sequence)
    return longest

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: "+str(solution(n)))
