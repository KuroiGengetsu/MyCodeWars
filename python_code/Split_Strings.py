def solution(s):
    lst = [s[i:i+2] for i in range(0, len(s), 2)]
    return lst if len(s) % 2 == 0 else lst[:-1] + [s[-1] + '_']

import re
def solution2(s):
    return re.findall(".{2}", s + '_')

def solution3(s):
    return [(s + '_')[i:i+2] for i in range(0, len(s), 2)]

def main():
    print(solution2('abc'))
    print(solution2('abcdef'))

if __name__ == '__main__':
    main()

