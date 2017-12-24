def duplicate_count(text):
    return sum(1 for i in set(text.lower()) if text.lower().count(i) > 1)

from collections import Counter
def duplicate_count2(text):
    return sum(1 for c, n in Counter(text.lower()).items() if n > 1) # iteritems() in python2.7

def main():
    print(duplicate_count2('Indivisibilities'))

if __name__ == '__main__':
    main()

