def accum(s):
    new_word  = ''
    for word, index in zip(s, range(1, len(s)+1)):
        new_word += (word * index).title() + '-'
    return new_word[:-1]

def accum2(s):
    return '-'.join([c.upper() + c.lower() * index for index, c in enumerate(s)])

def main():
    print(accum('abcd'))
    print(accum2('abcd'))

if __name__ == '__main__':
    main()

