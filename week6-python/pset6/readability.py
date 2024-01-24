def count_letters(text):
    count_letters = 0

    for char in text:
        if(char.isalpha()):
            count_letters += 1
    return count_letters


def count_words(text):      #func given by CS50 Duck
    words = text.split()
    return len(words)


def count_sentences(text):
    count_sentences = 0

    for char in text:
         if(char == "." or char == "?" or char == "!"):
             count_sentences += 1
    return count_sentences




def main():
    text = input("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = letters / words * 100
    S = sentences / words * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if(index >= 16):
        print("Grade 16+")
    elif(index < 1):
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


main()
