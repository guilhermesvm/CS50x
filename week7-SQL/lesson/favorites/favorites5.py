import csv
from collections import Counter

with open("lesson/favorites/favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    counts = Counter() #Automatically initialize values to zero

    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1

for favorite, count in counts.most_common(): 
    print(f"{favorite}: {counts[favorite]}")

