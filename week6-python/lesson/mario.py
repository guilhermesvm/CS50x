def get_int(prompt):
    while(True):
        try:
            return int(input(prompt))
        except ValueError:
            #print("Not an integer")
            pass

def main():
    while True:
        n = get_int("Height:")
        if(n > 0):
            break

    for i in range(n):
        print("#")


main()