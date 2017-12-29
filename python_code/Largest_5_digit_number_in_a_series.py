def solution(digits):
    return max(int(digits[i:i+5]) for i in range(len(digits)-4))

def main():
    print(solution("1234567890876"))

if __name__ == '__main__':
    main()

