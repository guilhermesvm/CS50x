people = [
    {"name": "Carter", "number": "123456"},
    {"name": "David", "number": "34567889"},
    {"name": "John", "number": "99999999"},
]

name = input("Name: ")

for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found {number}")
        break
else:
    print("Not found")