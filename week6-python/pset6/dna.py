import csv
import sys
import os


def main():

    # TODO: Check for command-line usage
    if(len(sys.argv) != 3):
        print("Usage: python dna.py databases/small.csv sequences/[n].txt")
        sys.exit()

    elif not os.path.exists(sys.argv[1]) or not os.path.exists(sys.argv[2]):
            print("File dos not exist")
            sys.exit()

    else:
        # TODO: Read database file into a variable
        databases = []
        with open(sys.argv[1]) as file:
            database = csv.DictReader(file)

            for row in database:
                databases.append(row)

        # TODO: Read DNA sequence file into a variable
        with open(sys.argv[2]) as file:
            dna = file.read()

        # TODO: Find longest match of each STR in DNA sequence | For each STR, compute the longest run of consecutive repeats in the DNA sequence
            strs = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
            for str in strs:
               repeats = longest_match(dna, str)

        # TODO: Check database for matching profiles | Compare the counts against each row in the CSV file
               for row in database:
                   if repeats

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
