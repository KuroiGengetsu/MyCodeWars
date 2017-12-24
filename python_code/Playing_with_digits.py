def dig_pow(n, p):
    sum = 0
    for digit in map(int, str(n)):
        sum += digit ** p
        p += 1
    k = int(sum / n)
    return k if k * n == sum else -1

def dig_pow2(n, p):
    s = 0
    for i, c in enumerate(str(n)):
        s += pow(int(c), p+i)
    return s/n if s%n == 0 else -1

def dig_pow3(n, p):
    k, fail = divmod(sum(int(d) ** (p + i) for i, d in enumerate(str(n))), n)
    return -1 if fail else k

def dig_pow4(n, p):
    s = reduce(lambda acc, (i, c): acc + pow(int(c), p+i), enumerate(str(n)), 0)
    return s/n if s%n == 0 else -1

def main():
    print(dig_pow(89, 1))
    print(dig_pow(92, 1))
    print(dig_pow(695, 2))
    print(dig_pow(46288, 3))
    print(dig_pow(12933, 7))

if __name__ == '__main__':
    main()

