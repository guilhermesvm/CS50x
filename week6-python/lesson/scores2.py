def get_int(prompt):
    while(True):
        try:
            return int(input(prompt))
        except ValueError:
            #print("Not an integer")
            pass


def main():
    scores = []

    for i in range(3):
        score = get_int("Score: ")
        scores.append(score)

    average = sum(scores) / len(scores)

    print(f"Average {average:.2f}")


main()