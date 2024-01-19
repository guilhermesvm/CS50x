import csv

books = []

## Add books to shelf by reading from read.csv
with open("read.csv") as file:
    reader = csv.DicReader(file) ##Iterate through the file and get a dictionary for every row
    for row in reader:
        books.append(row)

## Print books
    for book in books:
        print(book)