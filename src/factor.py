
# Find the prime factorization of a number.
# Command line utility.
# Josh Barney
# joshuareedbarney@gmail.com
# January 15th 2020

import math
import sys

def factor(n):
    if n==0:
        return
    index = 0
    sqrtOfN = math.sqrt(n) + 1
    arr = []

    while n != 1:
        i = 2
        while n % i != 0:
            if i > sqrtOfN:
                arr.append(int(n))
                return arr
            i += 1
        arr.append(int(i))
        n //= int(i)
        sqrtOfN = math.sqrt(n) + 1
    
    return arr
    
def main():
    if len(sys.argv) < 2:
        print("Please provide a number to factor")
        return

    n = int(sys.argv[1])
    
    if n <= 0:
        print(f'{n}: \n')
        return

    arr = sorted(factor(n))

    print(n, ':', end='', sep='')

    for item in arr:
        print(' ', item, end='', sep='')
    
    print()


if __name__=='__main__':
    main()
