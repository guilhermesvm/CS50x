def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            pass

def get_size():
    while True:
        height = get_int("Height: ")
        if(height > 0 and height < 9):
            return height
            break

def print_marioGridMore(height):
    for row in range(height):
        for space in range(height-row-1):
            print(" ", end="")
        for column in range(row+1):
            print("#", end="")

        print("  ", end="")

        for column2 in range(row+1):
            print("#", end="")

        print()





def main():
    height = get_size()
    print_marioGridMore(height)





main()


