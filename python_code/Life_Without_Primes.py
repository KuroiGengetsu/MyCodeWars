def solve(n):
    result = 1
    while n >= 0:
        while isPrime(result):
            result += 1
        s = str(result)
        if '2' in s or '3' in s or '5' in s or '7' in s:
            result += 1
            continue
        result += 1
        n -= 1
    return result - 1

def isPrime(x):
    if x == 1:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True


def main():
    for i in range(11):
        print(solve(i))
    # print(solve(10))
    # solve(2)


if __name__ == '__main__':
    main()