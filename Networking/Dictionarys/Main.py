programmers = {}

while True:
    user_input = input("Enter your given name, family name, and location.") 
    if user_input == "q": break
    name, famName,lName = user_input.split(',')
    programmers[name] = {"Name":name,"fName":famName,"lName":lName}

for programmer in programmers:
    print(f"username: {programmer.upper()}")
    for details in programmers[programmer]:
        print(f" - {details}: {programmers[programmer][details].title()}")