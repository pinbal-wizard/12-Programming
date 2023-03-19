import datetime


print("What is your name")
name = input("Name: ")
print("When were you born")
dob = input("dd/mm/yyyy: ")

if len(dob.split('/')) != 3:
    dob = dob.split('/')
    print(f"invalid syntax {dob},{len(dob)}")
else:
    dob = dob.split('/')
    dob = datetime.date(day=int(dob[0]),month=int(dob[1]),year=int(dob[2]))
    timenow = datetime.date.today()
    print(f"Hi {name.capitalize()}, you have been alive for {(timenow - dob).days} days")

