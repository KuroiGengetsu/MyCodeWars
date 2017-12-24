def alphabet_position(text):
    result = ''
    for c in text:
        if c.isalpha():
            result += str(ord(c.lower()) - ord('a') + 1) + ' '
        else:
            result += ' '
    return result

def alphabet_position2(text):
    return ' '.join([str(ord(c.lower()) - ord('a') + 1) 
        for c in text if c.isalpha()])

def main():
    print(alphabet_position2("The sunset sets at twelve o'clock."))

if __name__ == '__main__':
    main()

