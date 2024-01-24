import csv

with open("lesson/favorites/favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    counts = {} #creates and empty dictionary

    for row in reader: 
        favorite = row["language"]

        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for favorite in sorted(counts, key=counts.get, reverse=True): #iterates the highest to lowest
    print(f"{favorite}: {counts[favorite]}")

