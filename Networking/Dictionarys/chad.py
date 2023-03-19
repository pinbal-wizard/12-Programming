flag_progress = {}

while True:
    user_input = input("Enter Comp name, num participants, flags found") 
    if user_input == "q": break
    name, num,flag = user_input.split(',')
    flag_progress[name] = {"Name":name, "Num":num, "Flag":flag}

for programmer in flag_progress:
    print(f"name: {programmer.upper()}")
    for details in flag_progress[programmer]:
        print(f" - {details}: {flag_progress[programmer][details].title()}")