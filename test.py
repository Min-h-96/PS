def checkPrimeNum(n):
    check = True
    if n == 1:
        check = False
    else:
        for i in range(2, int(n**0.5)+1):
            if n % i == 0:
                check = False
                return None
            else:
                print(i)
                continue
    if check == True:
        return n


print(checkPrimeNum(997))
