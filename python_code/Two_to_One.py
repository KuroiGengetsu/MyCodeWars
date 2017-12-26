def longest(s1, s2):
    return ''.join(sorted(set(s1 + s2)))

def main():
    print(longest('xyaabbbccccdefww', 'xxxxyyyyabklmopq'))

if __name__ == '__main__':
    main()

