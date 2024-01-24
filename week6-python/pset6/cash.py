from cs50 import get_float

def get_cents():
    while True:
        dollars = get_float("Change: ")
        if (dollars > 0):
            return dollars
            break


def calculate_quarters(dollars):
    quarter = 0
    while (dollars >= 25):
        dollars = dollars - 25
        quarter += 1
    return quarter


def calculate_dimes(dollars):
    dime = 0
    while (dollars >= 10):
        dollars = dollars - 10
        dime += 1
    return dime


def calculate_nickels(dollars):
    nickel = 0
    while (dollars >= 5):
        dollars = dollars - 5
        nickel += 1
    return nickel


def calculate_pennies(dollars):
    penny = 0
    while (dollars >= 1):
        dollars = dollars - 1
        penny += 1
    return penny



def main():
    dollars = get_cents()
    dollars *= 100

    quarters = calculate_quarters(dollars)
    dollars = dollars - quarters * 25

    dimes = calculate_dimes(dollars)
    dollars = dollars - dimes * 10

    nickels = calculate_nickels(dollars)
    dollars = dollars - nickels * 5

    pennies = calculate_pennies(dollars)
    dollars = dollars - pennies * 1

    coins = quarters + dimes + nickels + pennies

    print(f"{coins}")


main()
