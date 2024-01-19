text = input("Enter a string: ")
text = text.strip() # Remove multiple occurrences of a character or characters which are mistakenly added at the beginning/end of strings
text = text.capitalize() #.upper() .lower()
text = text.split() #remvoes the white spaces in a sentence and turns it into a list of words

print(text)