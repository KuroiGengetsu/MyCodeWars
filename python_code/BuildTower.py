def tower_builder(n_floors):
    return [' ' * (n_floors - n) + '*' * (2*n-1) + ' ' * (n_floors - n) 
            for n in range(1, n_floors + 1)]

def tower_builder2(n_floors):
    return [('*' * (i * 2 - 1)).center(n_floors * 2 - 1)
            for i in range(1, n_floors + 1)]

def main():
    for i in range(1, 5):
        for level in tower_builder2(i):
            print(level)

if __name__ == '__main__':
    main()

