
def solution():
    fileloc ="problem0013.txt"
    result = 0
    with open(fileloc,"r") as file:
        file.seek(0)
        for line in file:
            result += int(line[0:13])
    return str(result)[0:10]

if __name__=="__main__":
    print("The solution is:" + str(solution()))
