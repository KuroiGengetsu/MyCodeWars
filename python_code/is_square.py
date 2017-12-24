def is_square(n):
    if n <= 0:
        return False
    elif int(n**0.5)**2 == n:
        return True
    else:
        return False

def is_square2(n):
    return False if n <= 0 or int(n**0.5)**2 != n else True

def main():
    print(is_square2(3))
    print(is_square2(4))
    print(is_square2(5))

if __name__ == '__main__':
    main()

