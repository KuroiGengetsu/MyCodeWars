def pig_it(text):
    return ' '.join([s if not s.isalpha() else s[1:] + s[0] + 'ay' for s in text.split()])

def main():
    print(pig_it('Pig latin is cool'))
    print(pig_it('Hello World !'))

if __name__ == '__main__':
    main()

