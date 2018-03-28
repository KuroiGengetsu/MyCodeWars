"""You will be given a number and you will need to return it
as a string in Expanded Form."""
import unittest


def expand_form(num):
    str_num = str(num)
    length = len(str_num)
    result = ''
    for index, bit in enumerate(list(str_num)):
        if int(bit) != 0:
            result += bit + '0' * (length - index - 1) + ' + '
    return result[:-3] if length > 1 else result


class TestExpandForm(unittest.TestCase):

    def test_expamd_form(self):
        self.assertEqual(expand_form(12), '10 + 2')
        self.assertEqual(expand_form(42), '40 + 2')
        self.assertEqual(expand_form(70304), '70000 + 300 + 4')


def main():
    unittest.main()

if __name__ == '__main__':
    main()

