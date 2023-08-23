import sys

def helper(sum,T):
    if len(T) == 0:
        return sum
    sum+= max(T[0])
    print(T.pop(0))
    return helper(sum,T)

    
    
def solution():
    fileloc = "problem0018.txt"
    T = []
    with open(fileloc,"r") as file:
        file.seek(0)
        for line in file:
            T.append(line.split())
    for i in range(len(T)):
        for j in range(len(T[i])):
            T[i][j] = int(T[i][j])
    return helper(0,T)
    
if __name__=="__main__":
    print("The solution is: " +str(solution()))
