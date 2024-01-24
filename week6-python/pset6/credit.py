from cs50 import get_int


def checksum(credit_card):
    digits = [int(digit) for digit in str(credit_card)]

    total = 0
    for i, digit in enumerate(reversed(digits)):
        if (i % 2 != 0):
            newDigit = (digit * 2)
            if (newDigit > 9):
                total += newDigit - 9
            else:
                total += newDigit
        else:
            total += digit

    if (total % 10 == 0):
        return True


def main():
    credit_card = get_int("Number: ")

    if checksum(credit_card):
        str_card = str(credit_card)
        if (len(str_card) == 15 and (str_card[:2] == '34' or str_card[:2] == '37')):
            print("AMEX")
        elif (len(str_card) == 16 and (51 <= int(str_card[:2]) <= 55)):
            print("MASTERCARD")
        elif ((len(str_card) == 13 or len(str_card) == 16) and str_card[0] == '4'):
            print("VISA")

    else:
        print("INVALID")


main()
