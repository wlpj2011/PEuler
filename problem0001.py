import sys

def solution(n):
    result = 0
    for i in range(1,n):
        if i%3 == 0 or i%5 == 0:
            result += i

    return result

if __name__ == "__main__":
    n = int(sys.argv[1])
    print("The solution is : "+ str(solution(n)))
