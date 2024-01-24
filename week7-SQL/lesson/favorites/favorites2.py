import csv

with open("lesson/favorites/favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        print(row["language"]) 