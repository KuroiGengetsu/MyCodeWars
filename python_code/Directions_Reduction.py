import re
def dirReduc(arr):
    regex = re.compile(r"[NS][NS]+|[WE][WE]+")
    raw = ''.join(arr).replace("NORTH", "N").replace("SOUTH", "S").replace("WEST", "W").replace("EAST", "E")
    result = ''
    mat = regex.findall(raw)
    while mat:
        result = mat
        mat = regex.findall(''.join(result))
        if result == mat:
            break
        #print(''.join(result))
    return ' '.join(result).replace("N", "NORTH").replace("S", "SOUTH").replace("W", "WEST").replace("E", "EAST")

def main():
    arr = ["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]
    print(dirReduc(arr))

if __name__ == '__main__':
    main()

