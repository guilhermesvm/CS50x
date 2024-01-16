people = {
    "Carter": "123456",
    "David": "34567889",
    "John": "99999999"
}

name = input("Name: ")

if name in people:
    number = people[name]
    print(f"Found {number}")
else:
    print("Not found")