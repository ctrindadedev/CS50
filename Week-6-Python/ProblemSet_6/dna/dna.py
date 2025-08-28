import csv
import sys


def main():
  

    # Check for command-line usage (Must have in the solution)
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    database = []
    try:
        #"r" is the way the program will read the file
        with open(sys.argv[1], "r") as csv_file:
            reader = csv.DictReader(csv_file)
            str_sequences = reader.fieldnames[1:]
            for row in reader:
                database.append(row)
    except FileNotFoundError:
        sys.exit(f"Error: Could not open CSV file {sys.argv[1]}.")

    # Read DNA sequence file into a variable
    try:
        with open(sys.argv[2], "r") as txt_file:
            dna_sequence = txt_file.read()
    except FileNotFoundError:
        sys.exit(f"Error: Could not open DNA sequence file {sys.argv[2]}.")

    # Find longest match of each STR in DNA sequence
    final_counts = {}
    for str_name in str_sequences:
        final_counts[str_name] = longest_match(dna_sequence, str_name)

    # Check database for matching profiles
    for person in database:
        match_count = 0
        for str_name in str_sequences:
            if int(person[str_name]) == final_counts[str_name]:
                match_count += 1

        # If all STR counts match
        if match_count == len(str_sequences):
            print(person["name"])
            return

    # If no match is found after checking all individuals
    print("No match")
    return


#CS50 made
def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

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


if __name__ == "__main__":
    main()
