from sys import argv #argc, argv[]

if len(argv) == 2:
    print(f"Hello, {argv[1]}!")
else:
    print("You must type a single command-line argument")