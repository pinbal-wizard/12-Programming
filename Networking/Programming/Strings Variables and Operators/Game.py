import random


def game():
    usrinput = input("guess number between 1 and 10 \n")
    num = random.randint(1,10)
    if usrinput.isnumeric() != True:
        print("thats not a number")
        return
    if usrinput == num:
        print("you win ")
        return
    else:
        print("your bad, skill issue, its ", num)
        return


print("Guessing gaming")
while(True):
    game()
   