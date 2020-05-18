import time
from itertools import compress

def sieve(limit):

    #if limit < 2:
        #return 0
    
    limit += 1
    st = time.time()
    primes = [True] * limit

    for i in range(2, int(limit ** 0.5 + 1)):
        if primes[i]:
            primes[i * i: limit: i] =  [False] * ((((limit - i*i) - 1) // i) + 1)

    primes[0] = primes[1] = False

    s = sum(compress(range(limit), primes))
    ed = time.time()
    print(f'Time: {ed - st: .4f}')

    return s

if __name__ == '__main__':

    s = sieve(10 ** 8)
    print(f'Sum: {s}')

