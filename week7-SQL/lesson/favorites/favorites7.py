import csv
from collections import Counter

with open("lesson/favorites/favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    counts = Counter() #Automatically initialize values to zero

    for row in reader:
        favorite = row["problem"]
        counts[favorite] += 1

    file.seek(0)  # Move the file pointer back to the beginning

    for row in reader:
        favorite2 = row["language"]
        counts[favorite2] += 1

favorite = input("Favorite Problem: ")
favorite2 = input("Favorite Language: ")
print(f"{favorite}: {counts[favorite]}")
print(f"{favorite2}: {counts[favorite2]}")



