def eratos(n):
    lst = [False, False] + [True]*(n-1)
    primes = []

    for i in range(2, n+1):
        if lst[i]:
            primes.append(i)
            for j in range(2*i, n+1, i):
                lst[j] = False
    return primes
