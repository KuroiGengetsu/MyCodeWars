def count_smileys(arr):
    smiles = [eye + nose + mouth
            for eye in [':', ';']
            for nose in ['', '-', '~']
            for mouth in [')', 'D']]
    i = 0
    for face in arr:
        i += 1 if face in smiles else 0
    return i

from re import findall
def count_smileys2(arr):
    return len(list(findall(r"[:;][-~]?[)D]", ' '.join(arr))))

# \A match only the start of the string
# \Z match only the end of the string
from re import match
def count_smileys3(arr):
    return sum(1 for s in arr if match(r"\A[:;][-~]?[)D]\Z", s))


def count_smileys4(arr):
    arr = [i.replace('-', '').replace('~', '') for i in arr]
    return sum(arr.count(i) for i in [':)', ':D', ';D', ';)'])

def count_smileys5(arr):
    return len(list(filter(lambda x: x in [':D', ':~D', ':-D', ';D',
        ';~D', ';-D', ':)', ':~)', ':-)', ';)', ';~)', ';-)'], arr)))

def main():
    arr = [':)', ';(', ';}', ':-D']
    print(count_smileys5(arr))

if __name__ == '__main__':
    main()

