import csv

with open("lesson/favorites/favorites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)    #gives the next line instead of the first

    for row in reader:
        print(row[1]) 