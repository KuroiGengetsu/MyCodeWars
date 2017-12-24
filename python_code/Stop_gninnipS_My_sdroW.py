def spin_words(sentence):
    sp_s = sentence.split()
    for i, s in enumerate(sp_s):
        if len(s) >= 5:
            sp_s[i] = ''.join(reversed(s))
    return ' '.join(sp_s)

def spin_words2(sentence):
    return ' '.join([s if len(s) < 5 else ''.join(reversed(s)) for s in sentence.split()])

def spin_words3(sentence):
    return ' '.join([s if len(s) < 5 else s[::-1] for s in sentence.split()])

def main():
    print(spin_words2('Welcome'))
    print(spin_words2('Hey fellow warriors'))
    print(spin_words2('This is a test'))
    print(spin_words2('This is another test'))

if __name__ == '__main__':
    main()

