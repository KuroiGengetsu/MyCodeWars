def longest_consec(strarr, k):
    n = len(strarr)
    if n == 0 or k > n or k <= 0:
        return ""
    lst = [len(s) for s in strarr]
    index = 0
    tmp = sum(lst[0:k])
    for i in range(1, n - k + 1):
        if sum(lst[i:i+k]) > tmp:
            index = i
    return ''.join(strarr[i:i+k])
def mylen(s):
    print(len(''.join(s)))
    return len(''.join(s))
def longest_consec2(strarr, k):
    n = len(strarr)
    if n == 0 or k > n or k <= 0:
        return ""
    sp = [strarr[i:i+k] for i in range(n - k + 1)]
    return ''.join(max(sp, key=mylen))

def main():
    print(longest_consec2(['zone', 'abigail', 'theta', 'form', 'libe', 'zas'], -2))
    print(longest_consec2(['it', 'wkppv', 'ixoyx', '3452', 'zzzzzzzzzzz'], 3))
    print(longest_consec2(['ejjjjmmtthh', 'zxxuueeg', 'aanlljrrrxx',
        'dqqqaaabbb', 'oocccffuucccjjjkkkjyyyeehh'], 1))

if __name__ == '__main__':
    main()

