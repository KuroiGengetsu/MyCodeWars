def find_next_square(sq):
    n = int(sq ** 0.5)
    return -1 if (n ** 2 != sq) else ((n + 1) ** 2)

def find_next_square2(sq):
    n = int(sq ** 0.5)
    return -1 if n % 1 else (n+1) ** 2

def main():
    print(find_next_square(121))
    print(find_next_square(625))
    print(find_next_square(319225))
    print(find_next_square(15241383936))
    print(find_next_square2(121))
    print(find_next_square2(625))
    print(find_next_square2(319225))
    print(find_next_square2(15241383936))

if __name__ == '__main__':
    main()

